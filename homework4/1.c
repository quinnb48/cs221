#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "1.h"
		
	int main(){
		list l = {NULL, 0};
		list* l2 = &l; 
		add(5, l2);
		add(7, l2);
		add(3, l2);
		add(14, l2);
		add(2, l2);
		uint32_t tl[3]={4, 2, 5};
		uint32_t tl2[5]={5, 7, 3, 14, 2};
		uint32_t tl3[1]={5};
		uint32_t tl4[2]={5,7};
		uint32_t tl5[2]={5,2};
		printf("\n");
		list* a = newTree(tl, 3);
		list* b = newTree(tl2, 5);
		list* c = newTree(tl3, 1);
		list* d = newTree(tl4, 2);
		list* e = newTree(tl5, 2);
		printf("\n");
		removeVal(c,7);
		removeVal(d,7);
		removeVal(e,2);
		printf("\n");
		fTree(a);
		fTree(b);
		fTree(c);
		fTree(d);
		fTree(e);
		return 0;
	}

	int add(uint32_t value, list* l){
		node* end = findEnd(l,value);
		node* newN = malloc(sizeof(node));
		newN->value = value;
		newN->left = NULL;
		newN->right = NULL;
		if(end == NULL){
			l->first = newN;
		}
		else{
			printf("end: %d, %d\n", value, end->value);
			if(value <= end->value){
				end->left = newN;
				
			}
			else{
				end->right = newN;
			}
		}
		node* current = l->first;
		while(current != NULL){
			printf("right vals: %d\n",current->value);
			current = current->right;
		}
		l->listSize++;
		return 0;
	}
	
	node* findEnd(list* l, uint32_t value){
		int loop=1;
		node* spot = l->first;
		while(loop==1){
			if(spot != NULL){
				if(value <= spot->value){
					if(spot->left != NULL){
						spot = spot->left;
					}
					loop = 0;
				}
				else{
					if(spot->right != NULL){
						spot = spot->right;
					}
					loop=0;
				}
			}
			else{
				loop=0;
			}
		}
		return spot;
	}
	
	list* newTree(uint32_t arr[], int size){
		list* newT = malloc(sizeof(list));
		newT->first = NULL;
		newT->listSize = 0;
		for(int i = 0; i < size; i++){
			add(arr[i],newT);
		}
		return newT;
	}
	
	int removeVal(list* l, uint32_t val){
		node* previous = NULL;
		node* current = l->first;
		int numRemoved = 0;
		int loop = 1;
		while(loop == 1){
			if(current!= NULL){
				if(current->value == val){
					//do removing stuff
					if(previous->left != NULL){
						if(previous->left->value == val){
							previous->left = previous->left->left;
							free(current);
						}
						numRemoved++;
						loop = 0;
					}
					else if(previous->right != NULL){
						if(previous->right->value == val){
							previous->right = previous->right->right;
							free(current);
						}
						numRemoved++;
						loop = 0;
					}
					
					
				}
				else if(val < current->value){
					previous = current;
					current = current->left;
				}
				else if(val > current->value){
					previous = current;
					current = current->right;
				}
			}
			else{
				loop = 0;
			}
		}
		printf("Removed: %d\n",numRemoved);
		return numRemoved;
	}
	
	int fTree(list* l){
		fTreeHelp(l->first);
		free(l);
		printf("Tree has been freed\n");
		return 0;
	}
	
	int fTreeHelp(node* n){
		if(n!=NULL){
			fTreeHelp(n->left);
			fTreeHelp(n->right);
			printf("Freeing: %d\n", n->value);
			free(n);
		}
		return 0;
	}
