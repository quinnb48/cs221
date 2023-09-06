#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "4.h"
	int main(){
		copySub("chatting",1,4);
		copySub("chatting",0,8);
		copySub("chatting",7,8);
		copySub("chatting",0,4);
	}
	
	char* copySub(char str1[], int start, int end){
		int length = end-start;
		char newS[length+1];
		int counter = 0;
		for(int i = start; i < end; i++){
			newS[counter]=str1[i];
			counter++;
		}
		char* pointer = newS;
		for(int k = 0; k < length; k++){
			printf("%c",newS[k]);
		}
		printf("\n");
		return pointer;
	}
