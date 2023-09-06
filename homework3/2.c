#include <stdio.h>
#include "2.h"
	int main(){
		logNegation(0);
		logNegation(1);
		logNegation(9);
		return 0;
	}
	
	int logNegation(int x){
		/*if int input is all 0, return 1. else return 0. no ifs, loops, function calls,\
		 or ! operator*/
		x = x & 1;
		x = x ^ 1;
		printf("%d\n",x);
		return x;
	}
