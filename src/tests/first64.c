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
#include <fhc/hilbert.h>

int main() {
	for (uint64_t idx=0; idx < 64; idx++) {
		fhc_point p=fhc_hilbert(idx);
		printf("%lu (%d, %d)\n",idx,p.x,p.y);
	}

	return 0;
}
