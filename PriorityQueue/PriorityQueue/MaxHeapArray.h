#pragma once
using namespace std;

class MaxHeapArray
{
public:
	void Push(vector<int>& Heap, const int& value);

	int Top(vector<int>& Heap);

	void Pop(vector<int>& Heap);

	void Traverse(const vector<int>& Heap);
private:
	int CalculateParentLocation(int Location);

	int CalculateLeftChildLocation(int Location);

	int CalculateRightChildLocation(int Location);
};

inline void MaxHeapArray::Push(vector<int>& Heap, const int& value)
{
	Heap.push_back(value);
	int PushLocation = static_cast<int>(Heap.size() - 1);

	while (PushLocation >= 1)
	{
		int ParentLocation = CalculateParentLocation(PushLocation);
		if (Heap[PushLocation] > Heap[ParentLocation])
		{
			swap(Heap[PushLocation], Heap[ParentLocation]);
			PushLocation = ParentLocation;
		}
		else
		{
			break;
		}
	}
}

inline int MaxHeapArray::Top(vector<int>& Heap)
{
	if (Heap.empty())
	{
		cout << "Heap이 비어있습니다.\n";
		return -1;
	}
	return Heap[0];
}

inline void MaxHeapArray::Pop(vector<int>& Heap)
{
	int HeapSize = static_cast<int>(Heap.size());
	if (HeapSize == 1)
	{
		Heap.pop_back();
		return;
	}
	swap(Heap[0], Heap.back());
	Heap.pop_back();
	HeapSize--;

	int Rotate = 0;

	while (Rotate < HeapSize)
	{
		int LeftChild = CalculateLeftChildLocation(Rotate);
		int RightChild = CalculateRightChildLocation(Rotate);
		if (RightChild < HeapSize)
		{
			if (Heap[Rotate] < Heap[LeftChild] && Heap[Rotate] < Heap[RightChild])
			{
				if (Heap[LeftChild] < Heap[RightChild])
				{
					swap(Heap[Rotate], Heap[RightChild]);
					Rotate = RightChild;
				}
				else
				{
					swap(Heap[Rotate], Heap[LeftChild]);
					Rotate = LeftChild;
				}
			}
			else if (Heap[Rotate] < Heap[LeftChild])
			{
				swap(Heap[Rotate], Heap[LeftChild]);
				Rotate = LeftChild;
			}
			else if (Heap[Rotate] < Heap[RightChild])
			{
				swap(Heap[Rotate], Heap[RightChild]);
				Rotate = RightChild;
			}
			else
				break;
		}
		else if (LeftChild < HeapSize)
		{
			if (Heap[Rotate] < Heap[LeftChild])
			{
				swap(Heap[Rotate], Heap[LeftChild]);
				Rotate = LeftChild;
			}
			else 
				break;
		}
		else
			break;
	}
}

inline void MaxHeapArray::Traverse(const vector<int>& Heap)
{
	for (const int& value : Heap)
	{
		cout << value << ' ';
	}
	cout << '\n';
}

inline int MaxHeapArray::CalculateParentLocation(int Location)
{
	Location -= 1;
	Location >>= 1;
	return Location;
}

inline int MaxHeapArray::CalculateLeftChildLocation(int Location)
{
	Location <<= 1;
	Location += 1;
	return Location;
}

inline int MaxHeapArray::CalculateRightChildLocation(int Location)
{
	Location <<= 1;
	Location += 2;
	return Location;
}
