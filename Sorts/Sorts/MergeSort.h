#pragma once
using namespace std;

template <typename T>
class MergeSorting
{
public:
	void MergeSort(T* arr, int low, int high)
	{
		if (low < high)
		{
			int Middle = low + ((high - low) >> 1);

			MergeSort(arr, low, Middle);
			MergeSort(arr, Middle + 1, high);

			Merge(arr, low, Middle, high);
		}
	}

private:
	void Merge(T* arr, int low, int middle, int high)
	{
		int LeftArrSize = middle - low + 1;
		int RightArrSize = high - middle;

		T* LeftSide = SetMergeArray(arr, low, LeftArrSize);
		T* RightSide = SetMergeArray(arr, middle + 1, RightArrSize);

		int L = 0, R = 0;
		int i = low;

		while (L < LeftArrSize || R < RightArrSize)
		{
			if (R >= RightArrSize || (L < LeftArrSize && LeftSide[L] <= RightSide[R]))
			{
				arr[i] = LeftSide[L];
				L++;
			}
			else
			{
				arr[i] = RightSide[R];
				R++;
			}
			i++;
		}
		delete[] LeftSide;
		delete[] RightSide;
	}

	T* SetMergeArray(T* arr, const int& begin, const int& size)
	{
		T* MergeArray = new T[size];

		for (int i = 0; i < size; i++)
		{
			MergeArray[i] = arr[begin + i];
		}

		return MergeArray;
	}
};
