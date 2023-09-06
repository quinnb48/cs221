#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "2.h"
	int main(){
		int a1[5] = {2,3,4,5,6};
		int a2[2] = {3,4};
		
		findDivisors(a1,5);
		findDivisors(a2,2);
	
	}
	
	int* findDivisors(int arr[], int size){
		int* result[2];
		int divisors[size];
		int divisees[size];
		result[0] = divisors;
		result[1] = divisees;
		int numPairs = 0;
		
		for(int i = 0; i<size; i++){
			divisors[i] = 0;
		}
		for(int i = 0; i<size; i++){
			divisees[i] = 0;
		}
		
		for(int i = 0; i<size; i++){
			for(int k = 0; k<size; k++){
				if((arr[i]%arr[k] == 0) && (arr[i] != arr[k])){
					divisees[numPairs] = arr[i];
					divisors[numPairs] = arr[k];
					numPairs++;
				}
			}
		}
		
		printf("Divisors: ");
		for(int i = 0; i<numPairs; i++){
			printf("%d, ",divisors[i]);
		}
		if(numPairs == 0){printf("0");}
		printf("\n");
		
		printf("Divisees: ");
		for(int i = 0; i<numPairs; i++){
			printf("%d, ",divisees[i]);
		}
		if(numPairs == 0){printf("0");}
		printf("\n");

		return *result;
	}
