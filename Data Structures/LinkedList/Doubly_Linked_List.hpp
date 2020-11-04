#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

typedef struct DoublyLinkedList{
	int data;
	struct DoublyLinkedList *prev, *next;
}DoublyNode;

void InitHead(DoublyNode *&head, DoublyNode *&tail){
	head = tail = NULL;
}

DoublyNode* CreateNode(int val){
	DoublyNode *q = new DoublyNode;
	q->data = val, q->prev = q->next = NULL;
	return q;
}

void AddHead(DoublyNode *&head, DoublyNode *&tail, int val){
	DoublyNode *q = CreateNode(val);
	if(head == NULL)
		head = tail = q;
	else
		head->prev = q, q->next = head, head = q;
}

void AddTail(DoublyNode *&head, DoublyNode *&tail, int val){
	DoublyNode *q = CreateNode(val);
	if(tail == NULL)
		head = tail = q;
	else
		tail->next = q, q->prev = tail, tail = q;
}

void AddAt(DoublyNode *&head, DoublyNode *&tail, int ele, int pos){
	if(pos == 1)
		AddHead(head, tail, ele);
	else{
		DoublyNode *i = head;
		int cnt = 2;
		while(i->next != NULL && cnt < pos)
			i = i->next, cnt ++;
		if(cnt == pos){
			if(i->next == NULL)
				AddTail(head, tail, ele);
			else{
				DoublyNode *q = CreateNode(ele);
				q->next = i->next, i->next->prev = q, i->next = q, q->prev = i;
			}
		}
	}
}

void DeleteHead(DoublyNode *&head, DoublyNode *&tail){
	if(head != NULL){
		DoublyNode *q = head;
		if(q->next == NULL)
			tail = NULL;
		head = head->next;
		if(head != NULL)
			head->prev = NULL;
		delete q;
	}
}

void DeleteTail(DoublyNode *&head, DoublyNode *&tail){
	if(tail != NULL){
		DoublyNode *q = tail;
		if(q->prev == NULL)
			head = NULL;
		tail = tail->prev;
		if(tail != NULL)
			tail->next = NULL;
		delete q;
	}
}

void DeleteAt(DoublyNode *&head, DoublyNode *&tail, int pos){
	if(pos == 1)
		DeleteHead(head, tail);
	else{
		DoublyNode *i = head;
		int cnt = 2;
		while(i != NULL && i->next != NULL){
			if(cnt == pos){
				if(i->next->next == NULL)
					DeleteTail(head, tail);
				else{
					DoublyNode *j = i->next;
					j->next->prev = i, i->next = j->next;
					delete j;
				}
			}
			i = i->next, cnt ++;
		}
	}
}

int GetAt(DoublyNode *head, DoublyNode *tail, int idx){
	int cnt = 1;
	while(head != NULL && head->next != NULL){
		if(cnt == idx)
			return head->data;
		cnt ++, head = head->next;
	}
	return -1;
}

int Search(DoublyNode *head, DoublyNode *tail, int val){
	int pos = 1;
	while(head != NULL){
		if(head->data == val)
			return pos;
		pos ++, head = head->next;
	}
	return -1;
}

void DeleteByValue(DoublyNode *&head, DoublyNode *&tail, int val){
	int pos = Search(head, tail, val);
	while(pos != -1)
		DeleteAt(head, tail, pos), pos = Search(head, tail, val);
}

void Input(DoublyNode *&head, DoublyNode *&tail){
	InitHead(head, tail);
	int n, val;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> val;
		AddTail(head, tail, val);
	}
}

void Output(DoublyNode *head, DoublyNode *tail){
	while(head != NULL){
		cout << head->data << ' ';
		head = head->next;
	}
	cout << '\n';
}

void OutputReverse(DoublyNode *head, DoublyNode *tail){
	while(tail != NULL){
		cout << tail->data << ' ';
		tail = tail->prev;
	}
	cout << '\n';
}

int Length(DoublyNode *head, DoublyNode *tail){
	int len = 0;
	while(head != NULL)
		len ++, head = head->next;
	return len;
}

#endif
