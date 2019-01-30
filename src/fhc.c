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

#include <fhc/bmi2.h>
#include <fhc/hilbert.h>
#include <fhc/gray_inv.h>

#ifndef __BMI2__
#include <fhc/bmi2_generic.h>
#endif

//BMI2 instantiations
uint64_t pext_u64(uint64_t src, uint64_t mask);
uint32_t pext_u32(uint32_t src, uint32_t mask);
uint64_t pdep_u64(uint64_t src, uint64_t mask);
uint32_t pdep_u32(uint32_t src, uint32_t mask);

//BMI2 generic instatiations
#ifndef __BMI2__
int ctz32(uint32_t val);
int ctz64(uint64_t val);
uint32_t helper_pext_u32(uint32_t src, uint32_t mask);
uint64_t helper_pext_u64(uint64_t src, uint64_t mask);
uint32_t helper_pdep_u32(uint32_t src, uint32_t mask);
uint64_t helper_pdep_u64(uint64_t src, uint64_t mask);
#endif

//hilbert instantiations
fhc_point fhc_hilbert(uint64_t idx);

//gray_inv instantiation
uint32_t fhc_gray_inv(uint32_t x);
