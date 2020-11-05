#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
using namespace std;

typedef struct SinglyLinkedList{
	int data;
	struct SinglyLinkedList *next;
	
	SinglyLinkedList* InitHead(){
		SinglyLinkedList *head = NULL;
		return head;
	}
	
	SinglyLinkedList* CreateNode(int val){
		SinglyLinkedList *q = new SinglyLinkedList;
		q->data = val, q->next = NULL;
		return q;
	}
	
	void AddHead(SinglyLinkedList *&head, int val){
		SinglyLinkedList *q = CreateNode(val);
		q->next = head, head = q;
	}
	
	void AddTail(SinglyLinkedList *&head, int val){
		SinglyLinkedList *q = CreateNode(val);
		if(head == NULL)
			head = q;
		else{
			SinglyLinkedList *i = head;
			while(i->next != NULL)
				i = i->next;
			i->next = q;
		}
	}
	
	void AddAt(SinglyLinkedList *&head, int ele, int pos){
		SinglyLinkedList *q = CreateNode(ele);
		if(pos == 1)
			q->next = head, head = q;
		else{
			int cnt = 2;
			SinglyLinkedList *i = head;
			while(i->next != NULL && cnt < pos)
				i = i->next, cnt ++;
			q->next = i->next, i->next = q;
		}
	}
	
	void DeleteHead(SinglyLinkedList *&head){
		if(head != NULL){
			SinglyLinkedList *q = head;
			head = head->next;
			delete q;
		}
	}
	
	void DeleteTail(SinglyLinkedList *&head){
		if(head != NULL){
			if(head->next == NULL){
				SinglyLinkedList *q = head;
				head = head->next;
				delete q;
			}
			else{
				SinglyLinkedList *i = head;
				while(i->next->next != NULL)
					i = i->next;
				SinglyLinkedList *j = i->next;
				i->next = j->next;
				delete j;
			}
		}
	}
	
	void DeleteAt(SinglyLinkedList *&head, int pos){
		if(pos == 1){
			if(head != NULL){
				SinglyLinkedList *q = head;
				head = head->next;
				delete q;
			}
		}
		else{
			int cnt = 2;
			SinglyLinkedList *i = head;
			while(i != NULL && i->next != NULL){
				if(cnt == pos){
					SinglyLinkedList *j = i->next;
					i->next = j->next;
					delete j;
				}
				i = i->next, cnt ++;
			}
		}
	}
	
	int GetAt(SinglyLinkedList *head, int idx){
		int cnt = 1;
		while(head != NULL && head->next != NULL){
			if(cnt == idx)
				return head->data;
			cnt ++, head = head->next;
		}
		return -1;
	}
	
	int Search(SinglyLinkedList *head, int val){
		int pos = 1;
		while(head != NULL){
			if(head->data == val)
				return pos;
			pos ++, head = head->next;
		}
		return -1;
	}
	
	void DeleteByValue(SinglyLinkedList *&head, int val){
		int pos = Search(head, val);
		while(pos != -1)
			DeleteAt(head, pos), pos = Search(head, val);
	}
	
	void Input(SinglyLinkedList *&head){
		head = InitHead();
		int n, val;
		cin >> n;
		for(int i = 0; i < n; i ++){
			cin >> val;
			AddTail(head, val);
		}
	}
	
	void Output(SinglyLinkedList *head){
		while(head != NULL){
			cout << head->data << ' ';
			head = head->next;
		}
		cout << '\n';
	}
	
	int Length(SinglyLinkedList *head){
		int len = 0;
		while(head != NULL)
			len ++, head = head->next;
		return len;
	}
}SinglyNode;

#endif
