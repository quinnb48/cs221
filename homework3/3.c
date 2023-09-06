#include <stdio.h>
#include <math.h>
#include "3.h"
	int main(){
		addTiny(0x01,0x07);
		addTiny(0x81,0x17);
		addTiny(0x89,0x81);
		return 0;
	}
	
	//takes two tiny floating point numbers, returns sum as a tiny floating point
	char addTiny(char x, char y){
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
		//((-1)^s1 * m1 * 2^e1 ) + ((-1)^s2 * m2 * 2^e2 )
		char m = m1 + m2;
		char e = e1;
		char s = 0;
		if(s1 == 1 || s2 == 1) s = -1;
		while(m >= 2){
			m = m >> 1;
			e++;
		}
		while(m<1){
			m = m << 1;
			e--;
		}
		char result = pow(-1,s) * pow(2,e) * m;	//pow returns ints. same problem on 4. otherwise fine
		printf("%d, %d, %d, %d\n",s,e,m, result);
		//printf converts result to ints but otherwise it's fine
		return result;
	}
