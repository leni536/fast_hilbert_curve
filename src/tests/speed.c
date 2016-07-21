#include<stdint.h>
#include "fast_hilbert_curve.h"

int main() {
	volatile point_pair pair;
	for(uint64_t idx=0; idx<100000000; idx++) {
		pair = fast_hilebert_curve( idx );
	}
	return 0;
}
