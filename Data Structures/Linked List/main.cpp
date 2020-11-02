#include "Single_Linked_List.hpp"

int main(){
	Node *head;
	Input(head);
	Output(head);
	cout << "TESTCASE 1: OK\n";
	AddHead(head, 10);
	Output(head);
	cout << "TESTCASE 2: OK\n";
	AddAt(head, 50, 1);
	Output(head);
	cout << "TESTCASE 3: OK\n";
	AddTail(head, 30);
	Output(head);
	cout << "TESTCASE 4: OK\n";
	DeleteHead(head);
	Output(head);
	cout << "TESTCASE 5: OK\n";
	DeleteAt(head, 1);
	Output(head);
	cout << "TESTCASE 6: OK\n";
	DeleteTail(head);
	Output(head);
	cout << "TESTCASE 7: OK\n";
	cout << GetAt(head, 1) << '\n';
	cout << "TESTCASE 8: OK\n";
	DeleteByValue(head, 50);
	Output(head);
	cout << "TESTCASE 9: OK\n";
	cout << Length(head) << '\n';
	cout << "TESTCASE 10: OK\n";
	char ok;
	do{
		cout << "PENDING... (Y/N):";
		cin.ignore();
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
