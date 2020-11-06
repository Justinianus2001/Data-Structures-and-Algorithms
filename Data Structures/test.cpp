#include "Data_Structures.hpp"

void judge(){
	char ok;	cin.ignore();
	do{
		cout << "PENDING... (Y/N): ";
		ok = getchar(), fflush(stdin);
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
	SinglyNode *head;
	head->Input(head), head->Output(head);
	cout << "TESTCASE 1: OK\n";
	head->AddHead(head, 10), head->Output(head);
	cout << "TESTCASE 2: OK\n";
	head->AddAt(head, 50, 1), head->Output(head);
	cout << "TESTCASE 3: OK\n";
	head->AddTail(head, 30), head->Output(head);
	cout << "TESTCASE 4: OK\n";
	head->DeleteHead(head), head->Output(head);
	cout << "TESTCASE 5: OK\n";
	head->DeleteAt(head, 1), head->Output(head);
	cout << "TESTCASE 6: OK\n";
	head->DeleteTail(head), head->Output(head);
	cout << "TESTCASE 7: OK\n";
	cout << head->GetAt(head, 1) << '\n';
	cout << "TESTCASE 8: OK\n";
	head->DeleteByValue(head, 50), head->Output(head);
	cout << "TESTCASE 9: OK\n";
	cout << head->Length(head) << '\n';
	cout << "TESTCASE 10: OK\n";
	judge();
}

void checkDoublyLinkedList(){
	DoublyNode *head, *tail;
	head->Input(head, tail), head->Output(head, tail);
	cout << "TESTCASE 1: OK\n";
	head->AddHead(head, tail, 10), head->Output(head, tail);
	cout << "TESTCASE 2: OK\n";
	head->AddAt(head, tail, 50, 1), head->Output(head, tail);
	cout << "TESTCASE 3: OK\n";
	head->AddTail(head, tail, 30), head->Output(head, tail);
	cout << "TESTCASE 4: OK\n";
	head->DeleteHead(head, tail), head->Output(head, tail);
	cout << "TESTCASE 5: OK\n";
	head->DeleteAt(head, tail, 1), head->Output(head, tail);
	cout << "TESTCASE 6: OK\n";
	head->DeleteTail(head, tail), head->Output(head, tail);
	cout << "TESTCASE 7: OK\n";
	cout << head->GetAt(head, tail, 1) << '\n';
	cout << "TESTCASE 8: OK\n";
	head->DeleteByValue(head, tail, 50), head->Output(head, tail), head->OutputReverse(head, tail);
	cout << "TESTCASE 9: OK\n";
	cout << head->Length(head, tail) << '\n';
	cout << "TESTCASE 10: OK\n";
	judge();
}

void checkCircularSinglyLinkedList(){
	CircularSinglyNode *tail;
	tail->Input(tail), tail->Output(tail);
	cout << "TESTCASE 1: OK\n";
	tail->AddHead(tail, 10), tail->Output(tail);
	cout << "TESTCASE 2: OK\n";
	tail->AddAt(tail, 50, 1), tail->Output(tail);
	cout << "TESTCASE 3: OK\n";
	tail->AddTail(tail, 30), tail->Output(tail);
	cout << "TESTCASE 4: OK\n";
	tail->DeleteHead(tail), tail->Output(tail);
	cout << "TESTCASE 5: OK\n";
	tail->DeleteAt(tail, 1), tail->Output(tail);
	cout << "TESTCASE 6: OK\n";
	tail->DeleteTail(tail), tail->Output(tail);
	cout << "TESTCASE 7: OK\n";
	cout << tail->GetAt(tail, 1) << '\n';
	cout << "TESTCASE 8: OK\n";
	tail->DeleteByValue(tail, 50), tail->Output(tail);
	cout << "TESTCASE 9: OK\n";
	cout << tail->Length(tail) << '\n';
	cout << "TESTCASE 10: OK\n";
	judge();
}

void checkBinarySearchTree(){
	BSNode *root = NULL;
	root->Input(root), root->PreOrder(root);
	cout << "\nTESTCASE 1: OK\n";
	root->InOrder(root);
	cout << "\nTESTCASE 2: OK\n";
	root->PostOrder(root);
	cout << "\nTESTCASE 3: OK\n";
	cout << root->Search(root, 30);
	cout << "\nTESTCASE 4: OK\n";
	root->DeleteByValue(root, 50), root->PreOrder(root);
	cout << "\nTESTCASE 5: OK\n";
	cout << root->Depth(root);
	cout << "\nTESTCASE 6: OK\n";
	judge();
}

void checkAVLTree(){
	AVLNode *root = NULL;
	root->Input(root), root->PreOrder(root);
	cout << "\nTESTCASE 1: OK\n";
	root->InOrder(root);
	cout << "\nTESTCASE 2: OK\n";
	root->PostOrder(root);
	cout << "\nTESTCASE 3: OK\n";
	cout << root->Search(root, 30);
	cout << "\nTESTCASE 4: OK\n";
	root->DeleteByValue(root, 10), root->PreOrder(root);
	cout << "\nTESTCASE 5: OK\n";
	cout << root->GetBalanceFactor(root);
	cout << "\nTESTCASE 6: OK\n";
	judge();
}

int main(){
	char ch;
	cout << "----- MENU TEST -----\n";
	cout << "1. Linked List\n";
	cout << "2. Tree\n";
	cout << "Enter your choice: ";		ch = getchar(), fflush(stdin);
	switch(ch){
		case '1':
			cout << "  1.1 Singly Linked List\n";
			cout << "  1.2 Doubly Linked List\n";
			cout << "  1.3 Circular Singly Linked List\n";
			cout << "Enter your choice: ";		ch = getchar(), fflush(stdin);
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
			cout << "  2.2 AVL Tree\n";
			cout << "Enter your choice: ";		ch = getchar(), fflush(stdin);
			switch(ch){
				case '1':
					checkBinarySearchTree();
					break;
				case '2':
					checkAVLTree();
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
