//#include "Singly_Linked_List.hpp"
#include "Doubly_Linked_List.hpp"

int main(){
//	SinglyNode *head;
	DoublyNode *head, *tail;
	
//	Input(head);
	Input(head, tail);
//	Output(head);
	Output(head, tail);
	cout << "TESTCASE 1: OK\n";
	
//	AddHead(head, 10);
//	Output(head);
	AddHead(head, tail, 10);
	Output(head, tail);
	cout << "TESTCASE 2: OK\n";
	
//	AddAt(head, 50, 1);
//	Output(head);
	AddAt(head, tail, 50, 1);
	Output(head, tail);
	cout << "TESTCASE 3: OK\n";
	
//	AddTail(head, 30);
//	Output(head);
	AddTail(head, tail, 30);
	Output(head, tail);
	cout << "TESTCASE 4: OK\n";
	
//	DeleteHead(head);
//	Output(head);
	DeleteHead(head, tail);
	Output(head, tail);
	cout << "TESTCASE 5: OK\n";
	
//	DeleteAt(head, 1);
//	Output(head);
	DeleteAt(head, tail, 1);
	Output(head, tail);
	cout << "TESTCASE 6: OK\n";
	
//	DeleteTail(head);
//	Output(head);
	DeleteTail(head, tail);
	Output(head, tail);
	cout << "TESTCASE 7: OK\n";
	
//	cout << GetAt(head, 1) << '\n';
	cout << GetAt(head, tail, 1) << '\n';
	cout << "TESTCASE 8: OK\n";
	
//	DeleteByValue(head, 50);
//	Output(head);
	DeleteByValue(head, tail, 50);
	Output(head, tail);
	OutputReverse(head, tail);
	cout << "TESTCASE 9: OK\n";
	
//	cout << Length(head) << '\n';
	cout << Length(head, tail) << '\n';
	cout << "TESTCASE 10: OK\n";
	
	char ok;
	cin.ignore();
	do{
		cout << "PENDING... (Y/N):";
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
	return EXIT_SUCCESS;
}
