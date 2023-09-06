#include <stdio.h>
#include <stdint.h>
	#ifndef L1_H
		#define L1_H
			typedef struct Node{
				uint32_t value;
				struct Node* right;
				struct Node* left;
			}node;
	
			typedef struct BTree{
				struct Node* first;
				int listSize;
			}list;
		
			int add(uint32_t, list*);
			node* findEnd(list*, uint32_t);
			list* newTree(uint32_t[], int size);
			int removeVal(list*, uint32_t);
			int fTree(list*);
			int fTreeHelp(node*);
	#endif
