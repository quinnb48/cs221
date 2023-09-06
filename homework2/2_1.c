#include <stdio.h>
#include "2_1.h"

	int main(int argc, char *argv[]){
			move(23);
			move(27);
			move(800);
			move(8000);
			return 0;
	}
	
	int alice(int boxes){
		int truckLoads = boxes / 23;
		if (boxes % 23 != 0){
			truckLoads++;
		}
		int cost = truckLoads * 200;
		return cost;
	}
	
	int bob(int boxes){
		int truckLoads = boxes / 30;
		if (boxes % 30 != 0){
			truckLoads++;
		}
		int cost = truckLoads * 260;
		return cost;
	}
	
	int move(int boxes){
		if(alice(boxes) < bob(boxes)){
			printf("\nAlice is cheaper");
			return alice(boxes);
		}
		else{
			printf("\nBob is cheaper");
			return bob(boxes);
		}
	}