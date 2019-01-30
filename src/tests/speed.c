#include <stdint.h>
#include <fhc/hilbert.h>

int main() {
	volatile fhc_point p;
	for(uint64_t idx=0; idx<100000000; idx++) {
		p = fhc_hilbert( idx );
	}
	return 0;
}
