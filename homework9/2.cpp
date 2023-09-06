#include <stdio.h>
#include <math.h>
#include <iostream>
#include <memory>
#include "2.h"

	int main(){
		return 0;
	}
	
	
	//node stuff
	//default
	node::node(){
		setRight(nullptr);
		setLeft(nullptr);
		setParent(nullptr);
		setVal(nullptr);
	}
	//creator
	node::node(node* right, node* left, node* parent, int* val){
		setRight(right);
		setLeft(left);
		setParent(parent);
		setVal(val);
	}
	//destructor
	node::~node(){
		delete [] right;
		delete [] left;
		delete [] parent;
		delete [] val;
	}
	//getters	
	node* node::getRight() const{
		return right;
	}
	node* node::getLeft() const{
		return left;
	}
	node* node::getParent() const{
		return parent;
	}
	int* node::getVal() const{
		return val;
	}
	//setters	
	void node::setRight(node*newRight){
		right = newRight;
	}
	void node::setLeft(node* newLeft){
		left = newLeft;
	}
	void node::setParent(node* newPar){
		parent = newPar;
	}
	void node::setVal(int* newVal){
		val = newVal;
	}


	//binSearchTree stuff
	//default
	binSearchTree::binSearchTree(){
		setRoot(nullptr);
		setNumElements(0);
	}
	//creator
	binSearchTree::binSearchTree(int numElem, int* arr[], int arrLength){//constructors can't return stuff??
		node newRoot(nullptr, nullptr, nullptr, arr[0]);				//so this doesn't return anything
		setRoot(&newRoot);
		for(int i = 1; i < arrLength; i++){
			node newy(nullptr, nullptr, nullptr, arr[i]);
			putInTree(&newy);
		}
		setNumElements(numElem);
	}
	binSearchTree::~binSearchTree(){
		delete [] root;
	}
	//getters	
	node* binSearchTree::getRoot() const{
		return root;
	}
	int binSearchTree::getNumElements() const{
		return numElements;
	}
	//setters
	void binSearchTree::setRoot(node* newRoot){
		root = newRoot;
	}
	void binSearchTree::setNumElements(int newNum){
		numElements = newNum;
	}
	//other stuff
	void binSearchTree::putInTree(node* newNode){
		node* temp(root);
		while(temp != nullptr){
			if(newNode->getVal() > temp->getVal()){
				temp = temp->getRight();
			}
			else if(newNode->getVal() < temp->getVal()){
				temp = temp->getLeft();
			}
			else{
				std::cout << "duplicate value\n";
				return;
			}
		}
		newNode->setParent(temp->getParent());
		if(newNode->getVal() > temp->getParent()->getVal()){
			temp->getParent()->setRight(newNode);
		}
		else{
			temp->getParent()->setLeft(newNode);
		}
		newNode->setParent(temp->getParent());
		delete [] temp;
	}
	
	int binSearchTree::removeFromTree(int removey){
		int didRemove = 0;
		node* temp(root);
		while(temp != nullptr){
			if(removey > *temp->getVal()){
				temp = temp->getRight();
			}
			else if(removey < *temp->getVal()){
				temp = temp->getLeft();
			}
			else{
				if(removey < *temp->getParent()->getVal()){
					if(temp->getRight()!= nullptr){
						getSmallestVal(temp->getRight())->setLeft(temp->getLeft());
						if(temp->getLeft() != nullptr){
							temp->getLeft()->setParent(getSmallestVal(temp->getRight()));
						}
						temp->getParent()->setLeft(temp->getRight());
						temp->getRight()->setParent(temp->getParent());
					}
					else{
						temp->getParent()->setLeft(temp->getLeft());
						if(temp->getLeft() != nullptr){
							temp->getLeft()->setParent(temp->getParent());
						}
					}
				}
				else if(removey > *temp->getParent()->getVal()){
					if(temp->getRight() != nullptr){
						getSmallestVal(temp->getRight())->setLeft(temp->getLeft());
						if(temp->getLeft() != nullptr){
							temp->getLeft()->setParent(getSmallestVal(temp->getRight()));
						}
						temp->getParent()->setRight(temp->getRight());
						temp->getRight()->setParent(temp->getParent());
						
					}
					else{
						temp->getParent()->setRight(temp->getLeft());
						if(temp->getLeft() != nullptr){
							temp->getLeft()->setParent(temp->getParent());
						}
					}
				}
				didRemove = 1;
			}
		}
		temp->~node();
		delete [] temp;
		return didRemove;
	}
	
	std::unique_ptr<node> binSearchTree::getSmallestVal(node* nodey){
		std::unique_ptr<node> temp(nodey);
		while(temp->getLeft() != nullptr){
			temp = temp->getLeft();
		}
		return temp;
	}
	

