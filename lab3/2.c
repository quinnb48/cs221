#include <stdio.h>
#include <stdint.h>
#include "2.h"
#define ARR_SIZE 5
	int main(){
		int arr1[ARR_SIZE]={1,2,3,4,5};
		int arr2[ARR_SIZE]={2,4,6,8,10};
		int arr3[ARR_SIZE]={1,3,5,7,9};
		rOdds(arr1);
		rOdds(arr2);
		rOdds(arr3);
		return 0;
	}

	int* rOdds(int arr[]){
		static int nArr[ARR_SIZE];
		for(int i = 0; i<ARR_SIZE; i++){
			nArr[i] = 0;
		}
		int k = 0;
		for(int i = 0; i<ARR_SIZE; i++){
			if(arr[i] % 2 == 0){
				nArr[k] = arr[i];
				printf(" %d,",nArr[k]);
				k++;
			}
		}
		if(k==0){printf(" 0");}
		printf("\n");
		return nArr;
	}
