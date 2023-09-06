#include <stdio.h>
#include <stdint.h>
#include "test.h"
	int main(){
		uint16_t aa[3] = {1.0,2.0,3.0};
		decaying_sum(aa,3,2);
		return 0;
	}

uint32_t decaying_sum(uint16_t* values, uint16_t length, uint16_t decay){
	if (length <= 0){
 		return 0;
	}
	uint32_t rest = decaying_sum(&values[1], length-1, decay);
	uint32_t decayed = rest / decay;
	printf("%d\n",values[0] + decayed);
 	return values[0] + decayed;
}
