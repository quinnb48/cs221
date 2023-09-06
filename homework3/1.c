#include <stdio.h>
#include "1.h"
	int main(){
		conditional(0,3,2);
		conditional(0,7,3);
		conditional(1,6,7);
		conditional(1,8,9);
		return 0;
	}
	
	int conditional(int x, int y, int z){
		/*if x=0, return z. else return y. No ifs, loops, or functions*/
		printf("%d\n",(x | z) & y);
		return (x | z) & y;
	}
