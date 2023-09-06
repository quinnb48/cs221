#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "1.h"
		
	int main(){
		list l = {NULL, NULL, 0};
		list* l2 = &l;
		add(5, l2);
		add(10, l2);
		add(76, l2);
		return 0;
	}

	int add(uint32_t value, list* l){
		node* newN = malloc(sizeof(node));
		newN->value = value;
		newN->next = NULL;
		if(l->listSize == 0){
			l->first = newN;
			l->last = newN;
		}
		else{
			l->last->next = newN;
		}
		l->listSize++;
		printf("num: %d\n", value);
		return 0;
	}
	
	int deAlloc(){
		return 0;
	}
