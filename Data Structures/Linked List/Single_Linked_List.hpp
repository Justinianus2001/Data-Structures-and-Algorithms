#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
using namespace std;

typedef struct SingleLinkedList{
	int data;
	struct SingleLinkedList *next;
}Node;

Node* InitHead(){
	Node *head = NULL;
	return head;
}

Node* CreateNode(int val){
	Node *q = new Node;
	q->data = val, q->next = NULL;
	return q;
}

void AddHead(Node *&head, int val){
	Node *q = CreateNode(val);
	q->next = head, head = q;
}

void AddTail(Node *&head, int val){
	Node *q = CreateNode(val);
	if(head == NULL)
		head = q;
	else{
		Node *i = head;
		while(i->next != NULL)
			i = i->next;
		i->next = q;
	}
}

void AddAt(Node *&head, int ele, int pos){
	Node *q = CreateNode(ele);
	if(pos == 1)
		q->next = head, head = q;
	else{
		int cnt = 2;
		Node *i = head;
		while(i->next != NULL && cnt < pos)
			i = i->next, cnt ++;
		q->next = i->next, i->next = q;
	}
}

void DeleteHead(Node *&head){
	if(head != NULL){
		Node *q = head;
		head = head->next;
		delete q;
	}
}

void DeleteTail(Node *&head){
	if(head != NULL){
		if(head->next == NULL){
			Node *q = head;
			head = head->next;
			delete(q);
		}
		else{
			Node *i = head;
			while(i->next->next != NULL)
				i = i->next;
			Node *j = i->next;
			i->next = j->next;
			delete j;
		}
	}
}

void DeleteAt(Node *&head, int pos){
	if(pos == 1){
		if(head != NULL){
			Node *q = head;
			head = head->next;
			delete q;
		}
	}
	else{
		int cnt = 2;
		Node *i = head;
		while(i != NULL && i->next != NULL){
			if(cnt == pos){
				Node *j = i->next;
				i->next = j->next;
				delete j;
			}
			i = i->next, cnt ++;
		}
	}
}

int GetAt(Node *head, int idx){
	int cnt = 1;
	while(head != NULL && head->next != NULL){
		if(cnt == idx)
			return head->data;
		cnt ++, head = head->next;
	}
	return -1;
}

int Search(Node *head, int val){
	int pos = 1;
	while(head != NULL){
		if(head->data == val)
			return pos;
		pos ++, head = head->next;
	}
	return -1;
}

void DeleteByValue(Node *&head, int val){
	int pos = Search(head, val);
	while(pos != -1)
		DeleteAt(head, pos), pos = Search(head, val);
}

void Input(Node *&head){
	head = InitHead();
	int n, val;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> val;
		AddTail(head, val);
	}
}

void Output(Node *head){
	while(head != NULL){
		cout << head->data << ' ';
		head = head->next;
	}
	cout << '\n';
}

int Length(Node *head){
	int len = 0;
	while(head != NULL)
		len ++, head = head->next;
	return len;
}

#endif
