#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "3b.h"
	int main() {
		makeCoords("333");
		makeCoords("171");
		makeCoords("");
		return 0;
       }
	
	int makeCoords(/*char* argc,*/ char* argv) {
		 int m = atoi(&argv[0]);
		 struct point2d *p = malloc(sizeof(struct point2d));
		 p->x = atoi(&argv[1]);
		 p->y = atoi(&argv[2]);
		 struct point2d *z = malloc(sizeof(struct point2d));
		 z->x = 0;
		 z->y = z->y - (m * p->x);
		 printf("x coord: %d\n", p->x);
		 printf("y coord: %d\n", p->y);
		 printf("x coord 2: %d\n", z->x);
		 printf("y coord 2: %d\n", z->y);
		 return 0;
       }
