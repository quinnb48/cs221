#include <stdio.h>
#include <math.h>
#include <iostream>
#include <memory>
#ifndef A2_H
		#define A2_H
		class node{
		public:
			node();
			node(node*, node*, node*, int*);
			~node();
		
			node* getRight() const;
			node* getLeft() const;
			node* getParent() const;
			int* getVal() const;
		
			void setRight(node*);
			void setLeft(node*);
			void setParent(node*);
			void setVal(int*);
		private:
			node* right;
			node* left;
			node* parent;
			int* val;
		};
		
		class binSearchTree{
		public:
			binSearchTree();
			binSearchTree(int, int*[], int);
			~binSearchTree();
			
			node* getRoot() const;
			int getNumElements() const;
			
			void setRoot(node*);
			void setNumElements(int);
			
			void putInTree(node*);
			int removeFromTree(int);
			std::unique_ptr<node> getSmallestVal(node*);
		private:
			node* root;
			int numElements;
		};

		#endif
