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

#ifndef UUID_D8112E71_9CCC_4E01_B9B9_6FC6B0226419
#define UUID_D8112E71_9CCC_4E01_B9B9_6FC6B0226419

#include <stdint.h>
#include <fhc/gray_inv.h>
#include <fhc/point.h>

#ifdef __BMI2__
#  include <x86intrin.h>
#else
#  include <fhc/bit_even_odd.h>
#endif

inline fhc_point fhc_hilbert(uint64_t idx) {
	uint32_t a,b,s1,s2;

#ifdef __BMI2__
	b=_pext_u64(idx,0x5555555555555555u); // even bits
	a=_pext_u64(idx,0xAAAAAAAAAAAAAAAAu); // odd bits
#else // ndef __BMI2__
	uint64_t x = fhc_separate_even_odd_bits(idx);
	b = x; // low bits = even bits
	a = (x >> 32); // high bits = odd bits
#endif // __BMI2__
	s1=(~a)&(~b);
	s2=a&b;

	s1=fhc_gray_inv(s1);
	s2=fhc_gray_inv(s2);

	a=(a^s1)^((~b)&(s1^s2));

	fhc_point p;
	p.x=a;
	p.y=a^b;

	return p;
}

#endif //  UUID_D8112E71_9CCC_4E01_B9B9_6FC6B0226419
