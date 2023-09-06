#include <stdio.h>
#include "3a.h"
	int main(){
		raiseXByY(2,4);
		raiseXByY(2,3);
		raiseXByY(2,0);
		raiseXByY(0,1);
		raiseXByY(1,2);
		raiseXByY(-5,2);
		raiseXByY(-5,3);
	}

    int raiseXByY(int x, int y) {
		int raise = 1;
		if(y == 0){
			x = 1;
		}
		while (y > 1) {
            if (y % 2 == 1) {
				raise = x * raise; 
			}
			x = x * x;
			y = y / 2; 
        }
        printf("%d\n",raise*x);
        return raise * x; 
	}
