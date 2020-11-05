#ifndef CIRCULAR_SINGLY_LINKED_LIST_HPP
#define CIRCULAR_SINGLY_LINKED_LIST_HPP

#include <iostream>
using namespace std;

typedef struct CircularSinglyLinkedList{
	int data;
	struct CircularSinglyLinkedList *next;
	
	CircularSinglyLinkedList* InitTail(){
		CircularSinglyLinkedList *tail = NULL;
		return tail;
	}
	
	CircularSinglyLinkedList* CreateNode(int val){
		CircularSinglyLinkedList *q = new CircularSinglyLinkedList;
		q->data = val, q->next = NULL;
		return q;
	}
	
	int Length(CircularSinglyLinkedList *tail){
		int len = 0;
		if(tail != NULL){
			CircularSinglyLinkedList *i = tail->next;
			len ++;
			while(i != tail)
				len ++, i = i->next;
		}
		return len;
	}
	
	void AddHead(CircularSinglyLinkedList *&tail, int val){
		CircularSinglyLinkedList *q = CreateNode(val);
		if(tail == NULL)
			tail = q, q->next = q;
		else
			q->next = tail->next, tail->next = q;
	}
	
	void AddTail(CircularSinglyLinkedList *&tail, int val){
		AddHead(tail, val);
		tail = tail->next;
	}
	
	void AddAt(CircularSinglyLinkedList *&tail, int ele, int pos){
		if(pos == 1)
			AddHead(tail, ele);
		else if(pos == Length(tail))
			AddTail(tail, ele);
		else if(pos > 1 && pos < Length(tail)){
			CircularSinglyLinkedList *i = tail->next, *q = CreateNode(ele);
			int cnt = 2;
			while(cnt < pos)
				i = i->next, cnt ++;
			q->next = i->next, i->next = q;
		}
	}
	
	void DeleteHead(CircularSinglyLinkedList *&tail){
		if(tail != NULL){
			if(tail == tail->next){
				CircularSinglyLinkedList *q = tail;
				tail = NULL;
				delete q;
			}
			else{
				CircularSinglyLinkedList *q = tail->next;
				tail->next = tail->next->next;
				delete q;
			}
		}
	}
	
	void DeleteTail(CircularSinglyLinkedList *&tail){
		if(tail != NULL){
			if(tail == tail->next){
				CircularSinglyLinkedList *q = tail;
				tail = NULL;
				delete q;
			}
			else{
				CircularSinglyLinkedList *i = tail->next;
				while(i->next != tail)
					i = i->next;
				CircularSinglyLinkedList *j = i->next;
				i->next = j->next, tail = i;
				delete j;
			}
		}
	}
	
	void DeleteAt(CircularSinglyLinkedList *&tail, int pos){
		if(pos == 1)
			DeleteHead(tail);
		else if(pos == Length(tail))
			DeleteTail(tail);
		else if(pos > 1 && pos < Length(tail)){
			CircularSinglyLinkedList *i = tail->next;
			int cnt = 2;
			while(cnt < pos)
				i = i->next, cnt ++;
			CircularSinglyLinkedList *j = i->next;
			i->next = j->next;
			delete j;
		}
	}
	
	int GetAt(CircularSinglyLinkedList *tail, int idx){
		if(tail != NULL){
			int cnt = 1;
			tail = tail->next;
			while(cnt <= idx){
				if(cnt == idx)
					return tail->data;
				cnt ++, tail = tail->next;
			}
		}
		return -1;
	}
	
	int Search(CircularSinglyLinkedList *tail, int val){
		if(tail != NULL){
			int pos = 1;
			CircularSinglyLinkedList *i = tail;
			do{
				i = i->next;
				if(i->data == val)
					return pos;
				pos ++;
			}while(i != tail);
		}
		return -1;
	}
	
	void DeleteByValue(CircularSinglyLinkedList *&tail, int val){
		int pos = Search(tail, val);
		while(pos != -1)
			DeleteAt(tail, pos), pos = Search(tail, val);
	}
	
	void Input(CircularSinglyLinkedList *&tail){
		tail = InitTail();
		int n, val;
		cin >> n;
		for(int i = 0; i < n; i ++){
			cin >> val;
			AddTail(tail, val);
		}
	}
	
	void Output(CircularSinglyLinkedList *tail){
		if(tail != NULL){
			CircularSinglyLinkedList *i = tail;
			do{
				i = i->next;
				cout << i->data << ' ';
			}while(i != tail);
		}
		cout << '\n';
	}
}CircularSinglyNode;

#endif
