#include <iostream>
#include <vector>
#include <random>
#include "MaxHeapArray.h"
using namespace std;

void MaxHeapArrayHandle();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	MaxHeapArrayHandle();

	return 0;
}

void MaxHeapArrayHandle()
{
	MaxHeapArray MH;
	vector<int> MaxHeap;

	random_device rd; // 시드값을 얻기 위한 random_device 생성.
	mt19937 gen(rd()); // random_device 를 통해 난수 생성 엔진을 초기화 한다.
	uniform_int_distribution<int> dis(0, 99);  // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.

	for (int i = 0; i < 20; i++)
	{
		int Random = dis(gen);
		cout << Random << ' ';
		MH.Push(MaxHeap, Random);
	}
	cout << '\n';
	while (!MaxHeap.empty())
	{
		cout << MH.Top(MaxHeap) << ' ';
		MH.Pop(MaxHeap);
	}
}
