//#include "LinkedList/Singly_Linked_List.hpp"
//#include "LinkedList/Doubly_Linked_List.hpp"
//#include "LinkedList/Circular_Singly_Linked_List.hpp"
#include "Tree/Binary_Search_Tree.hpp"

void judge(){
	char ok;	cin.ignore();
	do{
		cout << "PENDING... (Y/N): ";
		ok = getchar();
		if(ok == 'Y'){
			cout << "PRETEST PASSED !!!";
			break;
		}
		if(ok == 'N'){
			cout << "WRONG ANSWER !!!";
			break;
		}
	}while(true);
}

void checkSinglyLinkedList(){
//	SinglyNode *head;
//	Input(head), Output(head);
//	cout << "TESTCASE 1: OK\n";
//	AddHead(head, 10), Output(head);
//	cout << "TESTCASE 2: OK\n";
//	AddAt(head, 50, 1), Output(head);
//	cout << "TESTCASE 3: OK\n";
//	AddTail(head, 30), Output(head);
//	cout << "TESTCASE 4: OK\n";
//	DeleteHead(head), Output(head);
//	cout << "TESTCASE 5: OK\n";
//	DeleteAt(head, 1), Output(head);
//	cout << "TESTCASE 6: OK\n";
//	DeleteTail(head), Output(head);
//	cout << "TESTCASE 7: OK\n";
//	cout << GetAt(head, 1) << '\n';
//	cout << "TESTCASE 8: OK\n";
//	DeleteByValue(head, 50), Output(head);
//	cout << "TESTCASE 9: OK\n";
//	cout << Length(head) << '\n';
//	cout << "TESTCASE 10: OK\n";
//	judge();
}

void checkDoublyLinkedList(){
//	DoublyNode *head, *tail;
//	Input(head, tail), Output(head, tail);
//	cout << "TESTCASE 1: OK\n";
//	AddHead(head, tail, 10), Output(head, tail);
//	cout << "TESTCASE 2: OK\n";
//	AddAt(head, tail, 50, 1), Output(head, tail);
//	cout << "TESTCASE 3: OK\n";
//	AddTail(head, tail, 30), Output(head, tail);
//	cout << "TESTCASE 4: OK\n";
//	DeleteHead(head, tail), Output(head, tail);
//	cout << "TESTCASE 5: OK\n";
//	DeleteAt(head, tail, 1), Output(head, tail);
//	cout << "TESTCASE 6: OK\n";
//	DeleteTail(head, tail), Output(head, tail);
//	cout << "TESTCASE 7: OK\n";
//	cout << GetAt(head, tail, 1) << '\n';
//	cout << "TESTCASE 8: OK\n";
//	DeleteByValue(head, tail, 50), Output(head, tail), OutputReverse(head, tail);
//	cout << "TESTCASE 9: OK\n";
//	cout << Length(head, tail) << '\n';
//	cout << "TESTCASE 10: OK\n";
//	judge();
}

void checkCircularSinglyLinkedList(){
//	CircularSinglyNode *tail;
//	Input(tail), Output(tail);
//	cout << "TESTCASE 1: OK\n";
//	AddHead(tail, 10), Output(tail);
//	cout << "TESTCASE 2: OK\n";
//	AddAt(tail, 50, 1), Output(tail);
//	cout << "TESTCASE 3: OK\n";
//	AddTail(tail, 30), Output(tail);
//	cout << "TESTCASE 4: OK\n";
//	DeleteHead(tail), Output(tail);
//	cout << "TESTCASE 5: OK\n";
//	DeleteAt(tail, 1), Output(tail);
//	cout << "TESTCASE 6: OK\n";
//	DeleteTail(tail), Output(tail);
//	cout << "TESTCASE 7: OK\n";
//	cout << GetAt(tail, 1) << '\n';
//	cout << "TESTCASE 8: OK\n";
//	DeleteByValue(tail, 50), Output(tail);
//	cout << "TESTCASE 9: OK\n";
//	cout << Length(tail) << '\n';
//	cout << "TESTCASE 10: OK\n";
//	judge();
}

void checkBinarySearchTree(){
	TreeNode *root = NULL;
	Input(root);
	PreOrder(root);
	cout << "\nTESTCASE 1: OK\n";
	InOrder(root);
	cout << "\nTESTCASE 2: OK\n";
	PostOrder(root);
	cout << "\nTESTCASE 3: OK\n";
	cout << Search(root, 30);
	cout << "\nTESTCASE 4: OK\n";
	DeleteByValue(root, 50), PreOrder(root);
	cout << "\nTESTCASE 5: OK\n";
	cout << Depth(root);
	cout << "\nTESTCASE 6: OK\n";
	judge();
}

int main(){
	char ch;
	cout << "----- MENU TEST -----\n";
	cout << "1. Linked List\n";
	cout << "2. Tree\n";
	cout << "Enter your choice: ";		ch = getchar(), cin.ignore();
	switch(ch){
		case '1':
			cout << "  1.1 Singly Linked List\n";
			cout << "  1.2 Doubly Linked List\n";
			cout << "  1.3 Circular Singly Linked List\n";
			cout << "Enter your choice: ";		ch = getchar(), cin.ignore();
			switch(ch){
				case '1':
					checkSinglyLinkedList();
					break;
				case '2':
					checkDoublyLinkedList();
					break;
				case '3':
					checkCircularSinglyLinkedList();
					break;
				default:
					cout << "Choice Invalid !!!";
			}
			break;
		case '2':
			cout << "  2.1 Binary Search Tree\n";
			cout << "Enter your choice: ";		ch = getchar(), cin.ignore();
			switch(ch){
				case '1':
					checkBinarySearchTree();
					break;
				default:
					cout << "Choice Invalid !!!";
			}
			break;
		default:
			cout << "Choice Invalid !!!";
	}
	return EXIT_SUCCESS;
}
