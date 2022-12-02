#include <iostream>
#include <array>
#include "Unordered_map.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    UnorderedMap UM;

    UM.Insert(5, 10);
    UM.Insert(10);
    UM.Insert(8);
    UM.Insert(7);
    UM.Insert(15);
    UM.Insert(18);
    UM.Insert(9);
    cout << UM.Find(5) << '\n';
    cout << UM.Find(7) << '\n';
    cout << UM.GetValue(10) << '\n';
    cout << UM.GetValue(7) << '\n';
    UM.Traverse();
    cout << '\n';
    UM.Delete(9);
    UM.Traverse();

    return 0;
}
