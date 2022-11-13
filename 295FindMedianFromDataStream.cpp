#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
	void addNum(int num)
	{
		if (MaxHeap.empty() || num <= MaxHeap.top())
		{
			MaxHeap.push(num);
		}
		else
		{
			MinHeap.push(num);
		}

		if (MaxHeap.size() > MinHeap.size() + 1)
		{
			MinHeap.push(MaxHeap.top());
			MaxHeap.pop();
		}
		if (MinHeap.size() > MaxHeap.size())
		{
			MaxHeap.push(MinHeap.top());
			MinHeap.pop();
		}
	}

	double findMedian()
	{
		if (MaxHeap.size() > MinHeap.size())
		{
			return MaxHeap.top();
		}
		return (MaxHeap.top() + MinHeap.top()) / 2.0;
	}

private:
	priority_queue<int> MaxHeap;
	priority_queue<int, vector<int>, greater<int>> MinHeap;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	MedianFinder MF;
	MF.addNum(1);
	MF.addNum(2);
	cout << MF.findMedian() << '\n';
	MF.addNum(3);
	cout << MF.findMedian() << '\n';

	return 0;
}