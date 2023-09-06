#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
	#ifndef A2_H
		#define A2_H
		class node{
		public:
			node();
			node(std::string, int);
			~node();
			
			int getLength() const;
			std::string getString() const;
			node* getNext() const;
			node* getPrev() const;
			
			void setLength(int);
			void setString(std::string);
			void setNext(node*);
			void setPrev(node*);
			
		private:
			int length;
			node* next;
			node* prev;
			std::string string;
		};
		
		class linkedList{
		public:
			linkedList();
			linkedList(linkedList, int);
			~linkedList();
			linkedList(const linkedList &other);
			
			int getLength() const;
			int getSortStyle() const;
			node* getFirstNode() const;
			
			void setLength(int);
			void setSortStyle(int);
			void setFirstNode(node*);
			
			linkedList sortByLength(linkedList);
			linkedList sortByChar(linkedList);
			void addToList(node*,linkedList);
			void removeElement(std::string, linkedList);
			void clearList(linkedList);
			
			std::vector<std::string> getListValues(linkedList) const;
			std::string getIthValue(linkedList, int) const;
			bool isSortedByLength(linkedList) const;
			bool isSortedByChar(linkedList) const;
		private:
			int length;
			int sortStyle;
			node* firstNode;
		};
		
		
	#endif
