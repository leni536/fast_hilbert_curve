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

#include <fhc/hilbert.h>
#include <fhc/gray_inv.h>
#include <fhc/bit_permute_step.h>
#include <fhc/bit_even_odd.h>

//hilbert instantiations
fhc_point fhc_hilbert(uint64_t idx);

//gray_inv instantiation
uint32_t fhc_gray_inv(uint32_t x);

//bit_permute_step
uint64_t fhc_bit_permute_step(uint64_t x, uint64_t m, size_t shift);

//bit_even_odd
uint64_t fhc_separate_even_odd_bits(uint64_t x);
uint64_t fhc_shuffle_bits(uint64_t x);
