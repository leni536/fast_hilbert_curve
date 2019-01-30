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

#ifndef UUID_28556AE3_A588_4B31_987A_F4D5BD45C517
#define UUID_28556AE3_A588_4B31_987A_F4D5BD45C517

#include <fhc/bit_permute_step.h>

inline uint64_t fhc_separate_even_odd_bits(uint64_t x) {
	x = fhc_bit_permute_step(x, 0x2222222222222222, 1);
	x = fhc_bit_permute_step(x, 0x0c0c0c0c0c0c0c0c, 2);
	x = fhc_bit_permute_step(x, 0x00f000f000f000f0, 4);
	x = fhc_bit_permute_step(x, 0x0000ff000000ff00, 8);
	x = fhc_bit_permute_step(x, 0x00000000ffff0000, 16);
	return x;
}

inline uint64_t fhc_shuffle_bits(uint64_t x) {
	x = fhc_bit_permute_step(x, 0x00000000aaaaaaaa, 31);
	x = fhc_bit_permute_step(x, 0x00000000cccccccc, 30);
	x = fhc_bit_permute_step(x, 0x00000000f0f0f0f0, 28);
	x = fhc_bit_permute_step(x, 0x00000000ff00ff00, 24);
	x = fhc_bit_permute_step(x, 0x00000000ffff0000, 16);
	return x;
}

#endif //  UUID_28556AE3_A588_4B31_987A_F4D5BD45C517
