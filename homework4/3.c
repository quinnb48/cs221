#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "3.h"
	int main(){
		findString("apples", 6, "a", 1);
		findString("apples", 6, "p", 1);
		findString("apples", 6, "w", 1);
		findString("apples", 6, "pl", 2);
	}
	
	char* findString(char *str1, int length, char *str2, int l2){
		char* spot = &str1[length];
		for(int i = 0; i < length; i++){
			if(str1[i] == *str2){
				spot = &str1[i];
				break;
			}
		}
		printf("%c\n", *spot);
		return spot;
	}
