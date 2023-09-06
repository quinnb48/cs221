#include <stdio.h>
#include <math.h>
#include "2_3.h"

	int main(int argc, char *argv[]){
			powers(18);
			powers(1);
			powers(82);
			return 0;
	}
	
	int powers(int powerTo){
		int numPairs = 0;
		if (powerTo<=1){
			numPairs=0;
		}
		else{
			for(int i=2; i<powerTo; i++){
				for(int k=2; k<powerTo; k++){
					double p = pow(i,k);
					if (p <= powerTo){
						numPairs++;
					}
				}
			}
		}
		printf("%d\n",numPairs);
		return numPairs;
	}