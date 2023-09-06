#include <stdio.h>
#include <stdint.h>
	#ifndef L1_H
		#define L1_H
			typedef struct Node{
			uint32_t value;
			struct Node* next;
		}node;
	
		typedef struct LL{
			struct Node* first;
			struct Node* last;
			int listSize;
		}list;
		
		int add(uint32_t, list*);
		int deAlloc();
	#endif
