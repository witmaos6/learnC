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
    linkedList.InsertTail(list, 1);
    linkedList.Traverse(list);
    linkedList.InsertTail(list, 5);
    linkedList.InsertTail(list, 7);
    linkedList.Traverse(list);
    linkedList.InsertThis(list, 6, 5);
    linkedList.InsertThis(list, 9, 7);
    linkedList.Traverse(list);
    linkedList.InsertTail(list, 10);
    linkedList.Traverse(list);
    linkedList.DeleteThis(list, 1);
    linkedList.Traverse(list);
    linkedList.DeleteThis(list, 7);
    linkedList.DeleteThis(list, 5);
    linkedList.Traverse(list);
    linkedList.DeleteThis(list, 10);
    linkedList.Traverse(list);
    linkedList.InsertTail(list, 15);
    linkedList.Traverse(list);

    return 0;
}

// Node는 중복이 안되므로 private 클래스에 넣음
