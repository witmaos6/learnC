#pragma once
using namespace std;

class HeapSorting
{
public:
	template<typename T>
	void HeapSort(T* arr, int size)
	{
		for (int i = size - 1; i >= 0; i--)
		{
			Heapify(arr, size, i);
		}
		for (int i = size - 1; i >= 0; i--)
		{
			swap(arr[0], arr[i]);
			Heapify(arr, i, 0);
		}
	}

	template<typename T>
	void Heapify(T* arr, int n, int i)
	{
		int Largest = i;
		int Left = 2 * i + 1;
		int Right = 2 * i + 2;
		if (Left < n && arr[Left] > arr[Largest])
		{
			Largest = Left;
		}
		if (Right < n && arr[Right] > arr[Largest])
		{
			Largest = Right;
		}
		if (Largest != i)
		{
			swap(arr[i], arr[Largest]);
			Heapify(arr, n, Largest);
		}
	}
};
