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

#ifndef UUID_1E35ADD7_7959_4D01_91D6_EDC408AE4229
#define UUID_1E35ADD7_7959_4D01_91D6_EDC408AE4229

#include <fhc/point.h>
#include <fhc/bit_even_odd.h>

inline uint32_t fhc_s4_fold_step(uint32_t* v1, uint32_t* v0, uint32_t* c1, uint32_t* c0, uint32_t* h, size_t shift) {
	const uint32_t v1_rhs = (*v1 >> shift);
	const uint32_t v0_rhs = (*v0 >> shift);
	const uint32_t c1_rhs = (*c1 >> shift);
	const uint32_t c0_rhs = (*c0 >> shift);
	const uint32_t h_rhs  = (*h  >> shift);

	// S4 multiplications, original v1, v0,... form the lhs
	
	const uint32_t h_new = (*h) ^ h_rhs;

	const uint32_t phi_0 = ~c1_rhs | ((*h) ^ c0_rhs);
	const uint32_t phi_1 = c1_rhs;

	const uint32_t c0_new = ((*c1)^phi_0) | ((*c0)^phi_1);
	const uint32_t c1_new = ((*c1)^phi_1) | (phi_1^phi_0^(*c0));

	const uint32_t eta0 = (~(*h) & v0_rhs) | ((*h) & v1_rhs);
	const uint32_t eta1 = (~(*h) & v1_rhs) | ((*h) & v0_rhs);

	const uint32_t eta2_0 = ( (*c0)^eta1 | (*c1)^eta0) & (eta0 | eta1);
	const uint32_t eta2_1 = ((*c1)^eta1 | eta0^eta1^(*c0)) & (eta0 | eta1);

	const uint32_t v0_new = (*v0) ^ eta2_0;
	const uint32_t v1_new = (*v1) ^ eta2_1;

	*v0 = v0_new;
	*v1 = v1_new;
	*c0 = c0_new;
	*c1 = c1_new;
	*h  = h_new;

}

inline uint64_t fhc_hilbert_inv(fhc_point p) {
	uint32_t v1 = ~(p.x | p.y);
	uint32_t v0 = p.x & ~p.y;
	uint32_t c1 = -1;
	uint32_t c0 = p.x^p.y;
	uint32_t h  = -1;
	fhc_s4_fold_step(&v1, &v0, &c1, &c0, &h, 1);
	fhc_s4_fold_step(&v1, &v0, &c1, &c0, &h, 2);
	fhc_s4_fold_step(&v1, &v0, &c1, &c0, &h, 4);
	fhc_s4_fold_step(&v1, &v0, &c1, &c0, &h, 8);
	fhc_s4_fold_step(&v1, &v0, &c1, &c0, &h, 16);

	v1 >>= 1;
	v0 >>= 1;
	uint32_t idx1 = ((p.x ^ v1) & ~(v1 ^ v0)) | (~(p.y ^ v1) & (v1 ^ v0));
	return fhc_shuffle_bits(((uint64_t)idx1 << 32) | (uint64_t)(p.x^p.y));
}

#endif //  UUID_1E35ADD7_7959_4D01_91D6_EDC408AE4229
