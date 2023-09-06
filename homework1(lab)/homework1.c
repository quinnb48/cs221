 #include <stdio.h>
 #include <string.h>
 #include "homework1_4.c"
   int main (int argc, char *argv[]) {
   	 #define SIZE 2022
   	 int arrNum;
     printf("Hello, World! \nEnter a number: ");
     scanf("%d", &arrNum);
     int arr[SIZE];
     initialization(arr,SIZE,arrNum);
     printf("%d", arrNum);
     return 0;
}