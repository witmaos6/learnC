#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	LinkedList linkedList;
	List list;
	int Commad;

	do
	{
		cout << "명령을 입력하세요. \n";
		cout << "1 : InsertTail\n";
		cout << "2 : InsertThis\n";
		cout << "3 : DeleteThis\n";
		cout << "4 : Traverse\n";
		cout << "0 : Exit\n";
		cin >> Commad;
		switch (Commad)
		{
		case 1: int PushValue;
			cout << "push할 값을 입력하세요: ";
			cin >> PushValue;
			linkedList.InsertTail(list, PushValue);
			break;
		case 2:
			if (linkedList.bListEmpty(list))
			{
				cout << "List가 비어있습니다. ";
				break;
			}
			int InputValue, AfterValue;
			cout << "push할 값과 어떤 값 뒤에 넣을 것인지 입력하세요: ";
			cin >> InputValue >> AfterValue;
			linkedList.InsertThis(list, InputValue, AfterValue);
			break;
		case 3:
			if(linkedList.bListEmpty(list))
			{
				cout << "List가 비어있습니다. ";
				break;
			}
			int DeleteValue;
			cout << "삭제할 값을 입력하세요: ";
			cin >> DeleteValue;
			linkedList.DeleteThis(list, DeleteValue);
			break;
		case 4:
			if (linkedList.bListEmpty(list))
			{
				cout << "List가 비어있습니다. ";
				break;
			}
			cout << "리스트를 순회합니다 .\n";
			linkedList.Traverse(list);
			break;
		case 0: cout << "종료합니다. "; break;
		default: cout << "잘못된 명령입니다. \n"; break;
		}
	} while (Commad != 0);

	return 0;
}
