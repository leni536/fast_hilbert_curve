/*
 *  Copyright (c) 2003, 2016 Fabrice Bellard, Lénárd Szolnoki
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BMI2_GENERIC_H
#define BMI2_GENERIC_H

#include <stdint.h>

//copied and modified from QEMU sources

#if defined(__GNUC__) && defined(__GNUC_MINOR__)
# define QEMU_GNUC_PREREQ(maj, min) \
         ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
# define QEMU_GNUC_PREREQ(maj, min) 0
#endif

static inline int ctz32(uint32_t val)
{
#if QEMU_GNUC_PREREQ(3, 4)
    return val ? __builtin_ctz(val) : 32;
#else
    /* Binary search for the trailing one bit.  */
    int cnt;

    cnt = 0;
    if (!(val & 0x0000FFFFUL)) {
        cnt += 16;
        val >>= 16;
    }
    if (!(val & 0x000000FFUL)) {
        cnt += 8;
        val >>= 8;
    }
    if (!(val & 0x0000000FUL)) {
        cnt += 4;
        val >>= 4;
    }
    if (!(val & 0x00000003UL)) {
        cnt += 2;
        val >>= 2;
    }
    if (!(val & 0x00000001UL)) {
        cnt++;
        val >>= 1;
    }
    if (!(val & 0x00000001UL)) {
        cnt++;
    }

    return cnt;
#endif
}

static inline int ctz64(uint64_t val)
{
#if QEMU_GNUC_PREREQ(3, 4)
    return val ? __builtin_ctzll(val) : 64;
#else
    int cnt;

    cnt = 0;
    if (!((uint32_t)val)) {
        cnt += 32;
        val >>= 32;
    }

    return cnt + ctz32(val);
#endif
}

static uint32_t helper_pext_u32(uint32_t src, uint32_t mask)
{
    uint32_t dest = 0;
    int i, o;

    for (o = 0; mask != 0; o++) {
        i = ctz32(mask);
        mask &= mask - 1;
        dest |= ((src >> i) & 1) << o;
    }
    return dest;
}

static uint64_t helper_pext_u64(uint64_t src, uint64_t mask)
{
    uint64_t dest = 0;
    int i, o;

    for (o = 0; mask != 0; o++) {
        i = ctz64(mask);
        mask &= mask - 1;
        dest |= ((src >> i) & 1) << o;
    }
    return dest;
}

static uint64_t helper_pdep_u64(uint64_t src, uint64_t mask)
{
    uint64_t dest = 0;
    int i, o;

    for (i = 0; mask != 0; i++) {
        o = ctz64(mask);
        mask &= mask - 1;
        dest |= ((src >> i) & 1) << o;
    }
    return dest;
}

static uint32_t helper_pdep_u32(uint32_t src, uint32_t mask)
{
    uint32_t dest = 0;
    int i, o;

    for (i = 0; mask != 0; i++) {
        o = ctz32(mask);
        mask &= mask - 1;
        dest |= ((src >> i) & 1) << o;
    }
    return dest;
}

#endif //BMI2_GENERIC_H
