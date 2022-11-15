#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Tree T;
	int InitialValue = 0;
	cout << "Root값을 입력하세요: ";
	cin >> InitialValue;
	Node* Root = T.CreateNode(InitialValue);
	int Command = 0;

	do
	{
		cout << "명령을 입력하세요.\n";
		cout << "1.Insert\n";
		cout << "2.Find\n";
		cout << "3.Delete\n";
		cout << "4.BFS\n";
		cout << "5.DFS\n";
		cout << "6.InOrder\n";
		cin >> Command;
		switch (Command)
		{
		case 1: int InsertValue;
			cout << "push할 값을 입력하세요: ";
			cin >> InsertValue;
			T.Insert(Root, InsertValue);
			break;
		case 2: int FindValue;
			cout << "찾을 값을 입력하세요: ";
			cin >> FindValue;
			if(T.Find(Root, FindValue))
			{
				cout << "있습니다.\n";
			}
			else
			{
				cout << "없습니다.\n";
			}
			break;
		case 3: int DeleteValue;
			cout << "삭제할 값을 입력하세요: ";
			cin >> DeleteValue;
			T.Delete(Root, DeleteValue);
			break;
		case 4: cout << "너비 우선 탐색을 시작합니다.\n";
			T.BFS(Root);
			cout << endl;
			break;
		case 5: cout << "깊이 우선 탐색을 시작합니다.\n";
			T.DFS(Root);
			cout << endl;
			break;
		case 6: cout << "중위 순회를 시작합니다.\n";
			T.InOrder(Root);
			cout << endl;
			break;
		case 0: cout << "종료합니다. "; break;
		default: cout << "잘못된 명령입니다. \n"; break;
		}
	} while (Command != 0);

	return 0;
}