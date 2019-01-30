/*
 *  Copyright (c) 2016 Lénárd Szolnoki
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

#ifndef UUID_933CC346_9AAD_4677_AD8A_017F3C5F3292
#define UUID_933CC346_9AAD_4677_AD8A_017F3C5F3292

#include <stdint.h>

#ifdef __BMI2__
#  include <x86intrin.h>
#else
#  include "bmi2_generic.h"
#endif

static uint64_t pext_u64(uint64_t src, uint64_t mask) {
#ifdef __BMI2__
	return _pext_u64(src, mask);
#else
	return helper_pext_u64(src, mask);
#endif
}

static uint32_t pext_u32(uint32_t src, uint32_t mask) {
#ifdef __BMI2__
	return _pext_u32(src, mask);
#else
	return helper_pext_u32(src, mask);
#endif
}

static uint64_t pdep_u64(uint64_t src, uint64_t mask) {
#ifdef __BMI2__
	return _pdep_u64(src, mask);
#else
	return helper_pdep_u64(src, mask);
#endif
}

static uint32_t pdep_u32(uint32_t src, uint32_t mask) {
#ifdef __BMI2__
	return _pdep_u32(src, mask);
#else
	return helper_pdep_u32(src, mask);
#endif
}

#endif //  UUID_933CC346_9AAD_4677_AD8A_017F3C5F3292
