//
//  list.hpp
//  DataStructure
//
//  Created by BM on 4/3/24.
//

#ifndef list_h
#define list_h

class Node{
private:
	int data;
	Node *next;
	Node *prev;
	friend class LinkedList;
};

class LinkedList{
public:
	LinkedList();
	~LinkedList();
	void append(int data);
	void prepend(int data);
	int length();
	void print();
	void printReverse();
private:
	Node *head;
	Node *tail;
};


#endif /* list_hpp */
