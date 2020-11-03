#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
using namespace std;

typedef struct SinglyLinkedList{
	int data;
	struct SinglyLinkedList *next;
}SinglyNode;

SinglyNode* InitHead(){
	SinglyNode *head = NULL;
	return head;
}

SinglyNode* CreateNode(int val){
	SinglyNode *q = new SinglyNode;
	q->data = val, q->next = NULL;
	return q;
}

void AddHead(SinglyNode *&head, int val){
	SinglyNode *q = CreateNode(val);
	q->next = head, head = q;
}

void AddTail(SinglyNode *&head, int val){
	SinglyNode *q = CreateNode(val);
	if(head == NULL)
		head = q;
	else{
		SinglyNode *i = head;
		while(i->next != NULL)
			i = i->next;
		i->next = q;
	}
}

void AddAt(SinglyNode *&head, int ele, int pos){
	SinglyNode *q = CreateNode(ele);
	if(pos == 1)
		q->next = head, head = q;
	else{
		int cnt = 2;
		SinglyNode *i = head;
		while(i->next != NULL && cnt < pos)
			i = i->next, cnt ++;
		q->next = i->next, i->next = q;
	}
}

void DeleteHead(SinglyNode *&head){
	if(head != NULL){
		SinglyNode *q = head;
		head = head->next;
		delete q;
	}
}

void DeleteTail(SinglyNode *&head){
	if(head != NULL){
		if(head->next == NULL){
			SinglyNode *q = head;
			head = head->next;
			delete(q);
		}
		else{
			SinglyNode *i = head;
			while(i->next->next != NULL)
				i = i->next;
			SinglyNode *j = i->next;
			i->next = j->next;
			delete j;
		}
	}
}

void DeleteAt(SinglyNode *&head, int pos){
	if(pos == 1){
		if(head != NULL){
			SinglyNode *q = head;
			head = head->next;
			delete q;
		}
	}
	else{
		int cnt = 2;
		SinglyNode *i = head;
		while(i != NULL && i->next != NULL){
			if(cnt == pos){
				SinglyNode *j = i->next;
				i->next = j->next;
				delete j;
			}
			i = i->next, cnt ++;
		}
	}
}

int GetAt(SinglyNode *head, int idx){
	int cnt = 1;
	while(head != NULL && head->next != NULL){
		if(cnt == idx)
			return head->data;
		cnt ++, head = head->next;
	}
	return -1;
}

int Search(SinglyNode *head, int val){
	int pos = 1;
	while(head != NULL){
		if(head->data == val)
			return pos;
		pos ++, head = head->next;
	}
	return -1;
}

void DeleteByValue(SinglyNode *&head, int val){
	int pos = Search(head, val);
	while(pos != -1)
		DeleteAt(head, pos), pos = Search(head, val);
}

void Input(SinglyNode *&head){
	head = InitHead();
	int n, val;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> val;
		AddTail(head, val);
	}
}

void Output(SinglyNode *head){
	while(head != NULL){
		cout << head->data << ' ';
		head = head->next;
	}
	cout << '\n';
}

int Length(SinglyNode *head){
	int len = 0;
	while(head != NULL)
		len ++, head = head->next;
	return len;
}

#endif
