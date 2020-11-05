#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>
using namespace std;

typedef struct DoublyLinkedList{
	int data;
	struct DoublyLinkedList *prev, *next;
	
	void InitHead(DoublyLinkedList *&head, DoublyLinkedList *&tail){
		head = tail = NULL;
	}
	
	DoublyLinkedList* CreateNode(int val){
		DoublyLinkedList *q = new DoublyLinkedList;
		q->data = val, q->prev = q->next = NULL;
		return q;
	}
	
	void AddHead(DoublyLinkedList *&head, DoublyLinkedList *&tail, int val){
		DoublyLinkedList *q = CreateNode(val);
		if(head == NULL)
			head = tail = q;
		else
			head->prev = q, q->next = head, head = q;
	}
	
	void AddTail(DoublyLinkedList *&head, DoublyLinkedList *&tail, int val){
		DoublyLinkedList *q = CreateNode(val);
		if(tail == NULL)
			head = tail = q;
		else
			tail->next = q, q->prev = tail, tail = q;
	}
	
	void AddAt(DoublyLinkedList *&head, DoublyLinkedList *&tail, int ele, int pos){
		if(pos == 1)
			AddHead(head, tail, ele);
		else{
			DoublyLinkedList *i = head;
			int cnt = 2;
			while(i->next != NULL && cnt < pos)
				i = i->next, cnt ++;
			if(cnt == pos){
				if(i->next == NULL)
					AddTail(head, tail, ele);
				else{
					DoublyLinkedList *q = CreateNode(ele);
					q->next = i->next, i->next->prev = q, i->next = q, q->prev = i;
				}
			}
		}
	}
	
	void DeleteHead(DoublyLinkedList *&head, DoublyLinkedList *&tail){
		if(head != NULL){
			DoublyLinkedList *q = head;
			if(q->next == NULL)
				tail = NULL;
			head = head->next;
			if(head != NULL)
				head->prev = NULL;
			delete q;
		}
	}
	
	void DeleteTail(DoublyLinkedList *&head, DoublyLinkedList *&tail){
		if(tail != NULL){
			DoublyLinkedList *q = tail;
			if(q->prev == NULL)
				head = NULL;
			tail = tail->prev;
			if(tail != NULL)
				tail->next = NULL;
			delete q;
		}
	}
	
	void DeleteAt(DoublyLinkedList *&head, DoublyLinkedList *&tail, int pos){
		if(pos == 1)
			DeleteHead(head, tail);
		else{
			DoublyLinkedList *i = head;
			int cnt = 2;
			while(i != NULL && i->next != NULL){
				if(cnt == pos){
					if(i->next->next == NULL)
						DeleteTail(head, tail);
					else{
						DoublyLinkedList *j = i->next;
						j->next->prev = i, i->next = j->next;
						delete j;
					}
				}
				i = i->next, cnt ++;
			}
		}
	}
	
	int GetAt(DoublyLinkedList *head, DoublyLinkedList *tail, int idx){
		int cnt = 1;
		while(head != NULL && head->next != NULL){
			if(cnt == idx)
				return head->data;
			cnt ++, head = head->next;
		}
		return -1;
	}
	
	int Search(DoublyLinkedList *head, DoublyLinkedList *tail, int val){
		int pos = 1;
		while(head != NULL){
			if(head->data == val)
				return pos;
			pos ++, head = head->next;
		}
		return -1;
	}
	
	void DeleteByValue(DoublyLinkedList *&head, DoublyLinkedList *&tail, int val){
		int pos = Search(head, tail, val);
		while(pos != -1)
			DeleteAt(head, tail, pos), pos = Search(head, tail, val);
	}
	
	void Input(DoublyLinkedList *&head, DoublyLinkedList *&tail){
		InitHead(head, tail);
		int n, val;
		cin >> n;
		for(int i = 0; i < n; i ++){
			cin >> val;
			AddTail(head, tail, val);
		}
	}
	
	void Output(DoublyLinkedList *head, DoublyLinkedList *tail){
		while(head != NULL){
			cout << head->data << ' ';
			head = head->next;
		}
		cout << '\n';
	}
	
	void OutputReverse(DoublyLinkedList *head, DoublyLinkedList *tail){
		while(tail != NULL){
			cout << tail->data << ' ';
			tail = tail->prev;
		}
		cout << '\n';
	}
	
	int Length(DoublyLinkedList *head, DoublyLinkedList *tail){
		int len = 0;
		while(head != NULL)
			len ++, head = head->next;
		return len;
	}
}DoublyNode;

#endif
