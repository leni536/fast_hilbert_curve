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

#ifndef UUID_D9B7D6BF_42A9_430B_A3CD_66D30DD6EE51
#define UUID_D9B7D6BF_42A9_430B_A3CD_66D30DD6EE51

#include <fhc/bmi2.h>

inline uint32_t fhc_gray_inv(uint32_t x) {
	uint32_t evens, odds, popcount;
	evens=pdep_u32(0x55555555u,x);
	odds=pdep_u32(0xAAAAAAAAu,x);
	popcount=__builtin_popcountl(x);
	//if (popcount&1) {
	//	return (evens+(~odds));
	//} else {
	//	return ~(evens+(~odds));
	//}
	return (~(-(popcount & 1))) ^ (evens + (~odds));
}

#endif //  UUID_D9B7D6BF_42A9_430B_A3CD_66D30DD6EE51
