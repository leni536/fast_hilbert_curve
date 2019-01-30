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

#ifndef UUID_DBA339AC_D33E_4D33_A428_DD6D9F786813
#define UUID_DBA339AC_D33E_4D33_A428_DD6D9F786813

#include <stddef.h>
#include <stdint.h>

inline uint64_t fhc_bit_permute_step(uint64_t x, uint64_t m, size_t shift) {
	uint64_t t;
	t = ((x >> shift) ^ x) & m;
	x = (x ^ t) ^ (t << shift);
	return x;
}

#endif  //  UUID_DBA339AC_D33E_4D33_A428_DD6D9F786813
