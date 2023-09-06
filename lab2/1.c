#include <stdio.h>
#include "1.h"
	int main(){
		makeMask(3,9);
		return 0;
	}
	
	int makeMask(int start, int end){
		int numsToChange= end-start;
		int masky = 0xF0000000;
		masky = masky >> (numsToChange-1);
		masky = masky & 0x0FFFFFFF;
		masky = masky >> start;
		printf("%d",masky);
		return masky;
	}
