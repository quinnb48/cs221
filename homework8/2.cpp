#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include "2.h"
       
	int main () {
        printf("Hello, World!");
		return 0;
    }
	
	//default
	node::node(){
		setLength(0);
		setString("");
	}
	
	//creator
	node::node(std::string string, int length){
		setLength(length);
		setString(string);
	}
	
	//getters
	int node::getLength() const{
		return length;
	}
	
	std::string node::getString() const{
		return string;
	}
	
	node* node::getNext() const{
		return next;
	}
	
	node* node::getPrev() const{
		return prev;
	}
	
	//setters
	void node::setLength(int newLength){
		length = newLength;
	}
	
	void node::setString(std::string newString){
		string = newString;
	}
	
	void node::setNext(node* newNext){
		next = newNext;
	}
	
	void node::setPrev(node* newPrev){
		next = newPrev;
	}
	
	//destroyer
	node::~node(){
		if(next != nullptr){
			delete [] next;
		}
		if(prev != nullptr){
			delete [] prev;
		}
	}
	
	
	
	//default
	linkedList::linkedList(){
		setLength(0);
		setSortStyle(0);
		setFirstNode(nullptr);
	}
	
	//creator
	linkedList::linkedList(linkedList lst, int length){
		setLength(length);
		setSortStyle(0);//0 = sort by length. 1 = sort by character
		setFirstNode(lst.getFirstNode());
	}
	
	//copy creator
	linkedList::linkedList(const linkedList &other){
		setFirstNode(other.getFirstNode());//deep copy here
		setLength(other.getLength());
	}
	
	//getters
	int linkedList::getLength() const{
		return length;
	}
	
	int linkedList::getSortStyle() const{
		return sortStyle;
	}
	
	node* linkedList::getFirstNode() const{
		return firstNode;
	}
	
	//setters
	void linkedList::setLength(int newLength){
		length = newLength;
	}
	
	void linkedList::setSortStyle(int newStyle){
		sortStyle = newStyle;
	}
	
	void linkedList::setFirstNode(node* thing){
		firstNode = thing;
	}
	
	//destroyer
	linkedList::~linkedList(){
		//should delete everything inside list before using
		delete [] firstNode;
	}
	
	//others
	linkedList linkedList::sortByLength(linkedList lst){
		node* spot = lst.getFirstNode();
		int nodesToGetThrough = lst.getLength()-1;
		while(nodesToGetThrough > 0){
			if(spot->getNext() != nullptr){ //shifts node one spot up
				if(spot->getLength() > spot->getNext()->getLength()){
					spot->getNext()->setPrev(spot->getPrev());
					spot->setPrev(spot->getNext());
					spot->setNext(spot->getNext()->getNext());
					spot->getNext()->getPrev()->setNext(spot);
					spot->getNext()->setPrev(spot);
				}
			}
			else{
				spot = spot->getNext();
			}
			nodesToGetThrough--;	
		}
		delete [] spot;
		return lst;
	}
	
	linkedList linkedList::sortByChar(linkedList lst){
		node* spot = lst.getFirstNode();
		int nodesToGetThrough = lst.getLength()-1;
		while(nodesToGetThrough > 0){
			if(spot->getNext() != nullptr){ //shifts node one spot up
				if(spot->getString().compare(spot->getNext()->getString()) < 0){//if next str > spot str
					spot->getNext()->setPrev(spot->getPrev());
					spot->setPrev(spot->getNext());
					spot->setNext(spot->getNext()->getNext());
					spot->getNext()->getPrev()->setNext(spot);
					spot->getNext()->setPrev(spot);
				}
			}
			else{
				spot = spot->getNext();
			}
			nodesToGetThrough--;	
		}
		delete [] spot;
		return lst;
	}
	
	bool linkedList::isSortedByLength(linkedList lst) const{
		if(lst.getSortStyle() == 0){
			return true;
		}
		else{
			return false;
		}
	}
	bool linkedList::isSortedByChar(linkedList lst) const{
		if(lst.getSortStyle() == 1){
			return true;
		}
		else{
			return false;
		}
	}
	
	std::vector<std::string> linkedList::getListValues(linkedList lsty) const{
		std::vector<std::string> vec;
		node* spot = lsty.getFirstNode();
		for(int i = 0; i < lsty.getLength(); i++){
			vec.push_back(spot->getString());
			spot = spot->getNext();
		}
		delete [] spot;
		return vec;
	}
	
	std::string linkedList::getIthValue(linkedList lsty, int i) const{
		node* spot = lsty.getFirstNode();
		for(int k = 0; k < i; k++){
			spot = spot->getNext();
		}
		std::string temp = spot->getString();
		delete [] spot;
		return temp;
	}
	
	void linkedList::addToList(node* thing, linkedList lst){
		node* spot = lst.getFirstNode();
		if(lst.getSortStyle()==0){//add in length style
			for(int i = 0; i < lst.getLength(); i++){
				if(thing->getLength() > spot->getLength()){
					if(spot->getNext() != nullptr){
						spot = spot->getNext();
					}
					else{
						spot->setNext(thing);
					}
				}
				else{
					if(spot->getPrev() != nullptr){
						thing->setNext(spot);
						spot->getPrev()->setNext(thing);
					}
					else{
						thing->setNext(spot);
						spot->setPrev(thing);
					}
				}
			}
		}
		else{//add in char style
			for(int i = 0; i < lst.getLength(); i++){
				if(thing->getString().compare(spot->getString()) > 0){//if spot str comes before thing str, continue
					if(spot->getNext() != nullptr){
						spot = spot->getNext();
					}
					else{
						spot->setNext(thing);
					}
				}
				else{//if thing str comes before spot str, place
					if(spot->getPrev() != nullptr){
						thing->setNext(spot);
						spot->getPrev()->setNext(thing);
					}
					else{
						thing->setNext(spot);
						spot->setPrev(thing);
					}
				}
			}
		}
		delete [] spot;
	}
	
	void linkedList::removeElement(std::string val, linkedList lsty){
		node* spot = lsty.getFirstNode();
		for(int k = 0; k <= lsty.getLength(); k++){
			if(spot != nullptr){
				node* temp = spot->getNext();
				if(val.compare(spot->getString()) == 0){
					if(spot->getPrev() != nullptr){
						spot->getPrev()->setNext(spot->getNext());
					}
					if(spot->getNext() != nullptr){
						spot->getNext()->setPrev(spot->getPrev());
					}
				delete spot;
				}
				spot = temp;
			}
		}
		delete [] temp;
		delete [] spot;
	}
	
	void linkedList::clearList(linkedList lsty){
		node* spot = lsty.getFirstNode();
		for(int k = 0; k <= lsty.getLength(); k++){
			node* temp = spot->getNext()
			removeElement(spot->getString(), lsty);
			spot = temp;
		}
		delete [] temp;
		delete [] spot;
	}
