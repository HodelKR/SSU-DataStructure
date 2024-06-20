#ifndef list_h
#define list_h

#include<iostream>
using namespace std;

template <typename E>
class Node;

template <typename E>
class LinkedList;


template <typename E>
class Node{
private:
    E data;
    Node<E> *next;
    Node<E> *prev;

    friend class LinkedList<E>;
};

template <typename E>
class LinkedList{
public:
    LinkedList(const int size=2100000000);
    ~LinkedList();
    void add(const E& data);
    int length();
    void print();
    void printReverse();
private:
    Node<E> *head;
    Node<E> *tail;
    int maxEntry, cnt;
};


template <typename E>
LinkedList<E>::LinkedList(int size){
    cnt = 0;
    maxEntry = size;

    head = new Node<E>;
    tail = new Node<E>;
    head->next = tail;
    head->prev = nullptr;
    tail->next = nullptr;
    tail->prev = head;
}

template <typename E>
LinkedList<E>::~LinkedList(){
    Node<E> *tmp = head;

    while(tmp->next!=tail){
        tmp = head->next;
        delete head;
        head = tmp;
    }
    delete head;
    delete tail;
}

template <typename E>
void LinkedList<E>::add(const E& data){
    Node<E> *now = new Node<E>;
    now->data = data;
    
    if(head->next==tail){
        head->next = now;
        now->prev = head;
        now->next = tail;
        tail->prev = now;
        cnt += 1;
        return;
    }

    Node<E> *tmp1 = head->next;

    while(tmp1->data>data && tmp1->next!=nullptr){
        tmp1 = tmp1->next;
    }
    Node<E> *tmp2 = tmp1->prev;

    now->next = tmp1;
    now->prev = tmp2;

    tmp2->next = now;
    tmp1->prev = now;
    
    
    cnt += 1;
    if(cnt > maxEntry){
        cnt -= 1;
        tmp1 = tail->prev;
        tmp2 = tmp1->prev;
        tmp2->next = tail;
        tail->prev = tmp2;
        delete tmp1;
    }
}

template <typename E>
int LinkedList<E>::length(){
    return cnt;
}

template <typename E>
void LinkedList<E>::print(){
    Node<E> *tmp = head->next;
    while(tmp->next!=nullptr){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

template <typename E>
void LinkedList<E>::printReverse(){
    Node<E> *tmp = tail->prev;
    while(tmp->prev!=nullptr){
        cout << tmp->data << " ";
        tmp = tmp->prev;
    }
    cout << "\n";
}


#endif