#include <stdio.h>
#include <math.h>
#include "4.h"
	int main(){
		multTiny(0x01,0x07);
		multTiny(0x81,0x17);
		multTiny(0x89,0x81);
		return 0;
	}
	
	//takes two tiny floating point numbers, returns result as a tiny floating point
	char multTiny(char x, char y){
		char s1 = x & 0x80;   //isolate the numbers we want, shift them over for math
		if(s1){
			s1 = 0x01;
		}
		char s2 = y & 0x80;
		if(s2){
			s2 = 0x01;
		}
		char m1 = x & 0x07;
		char m2 = y & 0x07;
		char e1 = (x & 0x78)>>3;
		char e2 = (y & 0x78)>>3;
		//((-1)^s1 * m1 * 2^e1 ) * ((-1)^s2 * m2 * 2^e2 )
		char m = m1 * m2;
		char e = e1 + e2;
		char s = 0;
		if((s1 == 0 && s2 == 1) || (s1 == 1 && s2 == 0)) s = 0x01;
		char result = pow(-1,s) * pow(2,e) * m;	//pow returns ints,messes up math. angry. otherwise it's fine
		printf("%d, %d, %d, %d\n",s,e,m, result);
		//printf is also making it ints
		return result;
	}

