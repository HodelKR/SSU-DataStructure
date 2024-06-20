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
	tail = new Node;
	head->next = tail;
	head->prev = nullptr;
	tail->next = nullptr;
	tail->prev = head;
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
	while(tmp->next!=tail){
		tmp = tmp->next;
	}
	tmp->next = now;
	now->prev = tmp;
	now->next = tail;
	tail->prev = now;
}

void LinkedList::prepend(int data){
	Node *now = new Node;
	now->data = data;
	if(head->next==tail){
		head->next = now;
		now->prev = head;
		now->next = tail;
		tail->prev = now;
	}
	else {
		Node *tmp = head->next;
		head->next = now;
		now->prev = head;
		now->next = tmp;
		tmp->prev = now;
	}
}

int LinkedList::length(){
	Node *tmp = head;
	int ret = 0;
	while(tmp->next!=tail){
		ret++;
		tmp = tmp->next;
	}
	return ret;
}

void LinkedList::print(){
	Node *tmp = head->next;
	while(tmp->next!=tail){
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << tmp->data << "\n";
}

void LinkedList::printReverse(){
	Node *tmp = tail->prev;
	while(tmp->prev!=head){
		std::cout << tmp->data << " ";
		tmp = tmp->prev;
	}
	std::cout << tmp->data << "\n";
}
