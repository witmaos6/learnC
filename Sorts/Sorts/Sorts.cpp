#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <array>
#include <random>
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Search.h"
using namespace std;

template<typename T>
void PrintArray(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n";
}

int* SetRandomArray(const int& size)
{
	int* Array = new int[size];
	random_device rd; // 시드값을 얻기 위한 random_device 생성.
	mt19937 gen(rd()); // random_device 를 통해 난수 생성 엔진을 초기화 한다.
	uniform_int_distribution<int> dis(0, 20);  // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	for (int i = 0; i < size; i++)
	{
		Array[i] = dis(gen);
	}

	return Array;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	QuickSorting QS;
	Search S;
	int* Array = SetRandomArray(40);
	QS.QuickSort(Array, 0, 39);


	PrintArray(Array, 40);
	int FindValue = 15;

	for (int i = 0; i < 40; i++)
	{
		if (Array[i] >= FindValue)
		{
			cout << "Expected: " << i << '\n';
			break;
		}
	}

	cout << S.LowerBound(Array, 0, 39, FindValue);


	return 0;
}
