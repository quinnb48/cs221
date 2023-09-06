#include <stdio.h>
#include "2_4.h"

	int main(int argc, char *argv[]){
			fibonacci(2);
			fibonacci(3);
			fibonacci(8);
			return 0;
	}
	
	int fibonacci(int n){
		int result = 1;
		if(n <= 2){
			result = 1;
		}
		else{
			int prev = 1;
			int cur = 1;
			for (int i = 3; i <= n; i++){
				result = cur + prev;
				prev = cur;
				cur = result;
			}
		}
		printf("%d\n", result);
		return result;
	}