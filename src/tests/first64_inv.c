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

#include <stdint.h>
#include <stdio.h>
#include <fhc/hilbert_inv.h>

int main() {
	for (uint32_t x=0; x < 8; ++x) {
	for (uint32_t y=0; y < 8; ++y) {
		fhc_point p = {x, y};
		uint64_t idx = fhc_hilbert_inv(p);
		printf("%lu (%d, %d)\n", idx, x, y);

	}}
	return 0;
}
