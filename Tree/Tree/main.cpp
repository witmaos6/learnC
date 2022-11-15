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
	cout << "Root���� �Է��ϼ���: ";
	cin >> InitialValue;
	Node* Root = T.CreateNode(InitialValue);
	int Command = 0;

	do
	{
		cout << "����� �Է��ϼ���.\n";
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
			cout << "push�� ���� �Է��ϼ���: ";
			cin >> InsertValue;
			T.Insert(Root, InsertValue);
			break;
		case 2: int FindValue;
			cout << "ã�� ���� �Է��ϼ���: ";
			cin >> FindValue;
			if(T.Find(Root, FindValue))
			{
				cout << "�ֽ��ϴ�.\n";
			}
			else
			{
				cout << "�����ϴ�.\n";
			}
			break;
		case 3: int DeleteValue;
			cout << "������ ���� �Է��ϼ���: ";
			cin >> DeleteValue;
			T.Delete(Root, DeleteValue);
			break;
		case 4: cout << "�ʺ� �켱 Ž���� �����մϴ�.\n";
			T.BFS(Root);
			cout << endl;
			break;
		case 5: cout << "���� �켱 Ž���� �����մϴ�.\n";
			T.DFS(Root);
			cout << endl;
			break;
		case 6: cout << "���� ��ȸ�� �����մϴ�.\n";
			T.InOrder(Root);
			cout << endl;
			break;
		case 0: cout << "�����մϴ�. "; break;
		default: cout << "�߸��� ����Դϴ�. \n"; break;
		}
	} while (Command != 0);

	return 0;
}