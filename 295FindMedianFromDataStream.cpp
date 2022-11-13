// addNum는 컨테이너에 데이터를 추가하는 함수고 findMedian은 중간값을 찾는 함수다.(컨테이너 데이터 개수가 짝수 일 때는 중간값 두개의 합을 2로 나누어 반환한다.)
// class MedianFinder를 구현하라.
#include <iostream>
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
// 우선순위 큐를 공부할 때 MaxHeap과 MinHeap 두개를 이용하여 중간값을 빠르게 찾는 방법을 공부한 적이 있어서 수월하게 풀었다.
