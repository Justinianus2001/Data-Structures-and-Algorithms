#ifndef CIRCULAR_SINGLY_LINKED_LIST_H
#define CIRCULAR_SINGLY_LINKED_LIST_H

#include <iostream>
using namespace std;

typedef struct CircularSinglyLinkedList{
	int data;
	struct CircularSinglyLinkedList *next;
}CircularSinglyNode;

CircularSinglyNode* InitTail(){
	CircularSinglyNode *tail = NULL;
	return tail;
}

CircularSinglyNode* CreateNode(int val){
	CircularSinglyNode *q = new CircularSinglyNode;
	q->data = val, q->next = NULL;
	return q;
}

int Length(CircularSinglyNode *tail){
	int len = 0;
	if(tail != NULL){
		CircularSinglyNode *i = tail->next;
		len ++;
		while(i != tail)
			len ++, i = i->next;
	}
	return len;
}

void AddHead(CircularSinglyNode *&tail, int val){
	CircularSinglyNode *q = CreateNode(val);
	if(tail == NULL)
		tail = q, q->next = q;
	else
		q->next = tail->next, tail->next = q;
}

void AddTail(CircularSinglyNode *&tail, int val){
	AddHead(tail, val);
	tail = tail->next;
}

void AddAt(CircularSinglyNode *&tail, int ele, int pos){
	if(pos == 1)
		AddHead(tail, ele);
	else if(pos == Length(tail))
		AddTail(tail, ele);
	else if(pos > 1 && pos < Length(tail)){
		CircularSinglyNode *i = tail->next, *q = CreateNode(ele);
		int cnt = 2;
		while(cnt < pos)
			i = i->next, cnt ++;
		q->next = i->next, i->next = q;
	}
}

void DeleteHead(CircularSinglyNode *&tail){
	if(tail != NULL){
		if(tail == tail->next){
			CircularSinglyNode *q = tail;
			tail = NULL;
			delete q;
		}
		else{
			CircularSinglyNode *q = tail->next;
			tail->next = tail->next->next;
			delete q;
		}
	}
}

void DeleteTail(CircularSinglyNode *&tail){
	if(tail != NULL){
		if(tail == tail->next){
			CircularSinglyNode *q = tail;
			tail = NULL;
			delete q;
		}
		else{
			CircularSinglyNode *i = tail->next;
			while(i->next != tail)
				i = i->next;
			CircularSinglyNode *j = i->next;
			i->next = j->next, tail = i;
			delete j;
		}
	}
}

void DeleteAt(CircularSinglyNode *&tail, int pos){
	if(pos == 1)
		DeleteHead(tail);
	else if(pos == Length(tail))
		DeleteTail(tail);
	else if(pos > 1 && pos < Length(tail)){
		CircularSinglyNode *i = tail->next;
		int cnt = 2;
		while(cnt < pos)
			i = i->next, cnt ++;
		CircularSinglyNode *j = i->next;
		i->next = j->next;
		delete j;
	}
}

int GetAt(CircularSinglyNode *tail, int idx){
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

int Search(CircularSinglyNode *tail, int val){
	if(tail != NULL){
		int pos = 1;
		CircularSinglyNode *i = tail;
		do{
			i = i->next;
			if(i->data == val)
				return pos;
			pos ++;
		}while(i != tail);
	}
	return -1;
}

void DeleteByValue(CircularSinglyNode *&tail, int val){
	int pos = Search(tail, val);
	while(pos != -1)
		DeleteAt(tail, pos), pos = Search(tail, val);
}

void Input(CircularSinglyNode *&tail){
	tail = InitTail();
	int n, val;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> val;
		AddTail(tail, val);
	}
}

void Output(CircularSinglyNode *tail){
	if(tail != NULL){
		CircularSinglyNode *i = tail;
		do{
			i = i->next;
			cout << i->data << ' ';
		}while(i != tail);
	}
	cout << '\n';
}

#endif
