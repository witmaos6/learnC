#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> Queue1 = { 3,2,7,2 };
	vector<int> Queue2 = { 4,6,5,1 };

	cout << solution(Queue1, Queue2);

	return 0;
}

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = -1;
	long long Current1Total = accumulate(queue1.begin(), queue1.end(), 0);
	long long Current2Total = accumulate(queue2.begin(), queue2.end(), 0);
	long long Total = Current1Total + Current2Total;
	queue1.insert(queue1.end(), queue2.begin(), queue2.end());

	if ((Total & 1) == 1)
	{
		return answer;
	}
	answer = 0;

	int NewQueueSize = static_cast<int>(queue1.size());
	int QueueSize = static_cast<int>(queue2.size());
	int Point1 = 0, Point2 = QueueSize;
	QueueSize <<= 2;
	while (answer <= QueueSize)
	{
		if (Current1Total > Current2Total)
		{
			Current1Total -= queue1[Point1];
			Current2Total += queue1[Point1];
			Point1++;
			if (Point1 >= NewQueueSize)
			{
				Point1 = 0;
			}
		}
		else if (Current1Total < Current2Total)
		{
			Current2Total -= queue1[Point2];
			Current1Total += queue1[Point2];
			Point2++;
			if (Point2 >= NewQueueSize)
			{
				Point2 = 0;
			}
		}
		else
		{
			return answer;
		}
		answer++;
	}

	return -1;
}