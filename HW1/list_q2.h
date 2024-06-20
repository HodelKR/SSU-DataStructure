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
private:
	Node *head;
};


#endif /* list_hpp */
