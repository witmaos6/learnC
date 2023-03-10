#pragma once
using namespace std;

class QuickSorting
{
public:
	template<typename T>
	void QuickSort(T* arr, int low, int high)
	{
		if (low < high)
		{
			int p = Partition(arr, low, high);
			QuickSort(arr, low, p - 1);
			QuickSort(arr, p + 1, high);
		}
	}

private:
	template<typename T>
	int  Partition(T* arr, int low, int high)
	{
		int pivot = arr[high];
		int i = low - 1;

		for (int j = low; j < high; j++)
		{
			if (arr[j] <= pivot)
			{
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[high]);
		return i + 1;
	}
};
