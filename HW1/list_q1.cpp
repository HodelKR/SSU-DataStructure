//
//  list.cpp
//  DataStructure
//
//  Created by BM on 4/3/24.
//
#include <iostream>
#include "list.h"

LinkedList::LinkedList(){
	head = new Node;
	head->next = nullptr;
}

LinkedList::~LinkedList(){
	Node *tmp;
	
	while(head->next!=nullptr){
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

void LinkedList::append(int data){
	Node *now = new Node;
	now->data = data;
	Node *tmp = head;
	while(tmp->next!=nullptr){
		tmp = tmp->next;
	}
	tmp->next = now;
}

int LinkedList::length(){
	Node *tmp = head;
	int ret = 0;
	while(tmp->next!=nullptr){
		ret++;
		tmp = tmp->next;
	}
	return ret;
}

void LinkedList::print(){
	Node *tmp = head->next;
	while(tmp->next!=nullptr){
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << tmp->data << "\n";
}
