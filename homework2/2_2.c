#include <stdio.h>
#include "2_2.h"
	int main(void){
		int a[4] = {3,8,12,20};
		int b[5] = {5,3,1,8,10};
		int c[4]={5,6,7,6};
		int d[3]={6,7,8};
		int e[1]={4};
		int f[0]={};
		find_divisor(a,4);
		find_divisor(b,5);
		find_divisor(c,4);
		find_divisor(d,3);
		find_divisor(e,1);
		find_divisor(f,0);
		return 0;
	}
	
	int find_divisor(int arr[], int size){
		int num1 = 0;
		int num2 = 0;
		if (size == 0 || size == 1){
			num1=0;
			num2=0;
		}
		else{
			for(int i=0; i<size-1; i++){
				for(int k=i+1; k<size; k++){
					if(arr[k] % arr[i] == 0){
						num1 = arr[i];
						num2 = arr[k];
					}
				}
			}
		}
		printf("(%d,",num1);
		printf("%d)\n",num2);
		return 0;
	}