#include <stdio.h>
#include "homework1_4.h"
	int initialization(int arr[], int size, int value){
		for(int i=0; i<size; i++){
     		arr[i]=value;
     	}
		return 0;
	}