// 길이가 같은 두개의 queue가 주어진다. queue는 vector로 이루어져 있으며 하나의 큐에서 pop연산을 실행하면 그 값은 다른 vector의 back으로 push된다.
// 두개의 queue의 원소의 합이 같아야 하는데 최소 연산으로 구하라. pop()과 push_back() 두개의 연산이 한번이다. 같아지지 않는다면 -1을 반환한다.
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
	long long Current1Total = accumulate(queue1.begin(), queue1.end(), 0); // 주어진 queue1의 원소의 합이다.
	long long Current2Total = accumulate(queue2.begin(), queue2.end(), 0); // 주어진 queue2의 원소의 합이다.
	long long Total = Current1Total + Current2Total;
	queue1.insert(queue1.end(), queue2.begin(), queue2.end());

	if ((Total & 1) == 1) // 두 queue의 합이 홀수 라면 정수범위에서 두 vector의 합계는 같아질 수가 없다.
	{
		return answer;
	}
	answer = 0;

	int NewQueueSize = static_cast<int>(queue1.size());
	int QueueSize = static_cast<int>(queue2.size());
	int Point1 = 0, Point2 = QueueSize;
	QueueSize <<= 2; // 연산의 횟수가 주어진 queue의 4배라면 모든 경우의 수를 살핀 상태로 간주 할 수 있다.
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
// 하나의 queue에는 최대 30만개의 원소가 들어갈 수 있고 하나의 queue에서 값을 빼면 그 값은 다른 queue로 가게된다.
// 위에 조건에서 queue는 페이크라는 것을 눈치챘다. queue를 이용하는 것이 아닌 특징을 생각해야 한다.
// queue의 특징을 생각한다면 하나의 queue의 원소의 합은 두 개의 queue를 연결했을 때 연속되는 sub vector의 원소의 합이라는 것을 알 수 있다.
// Point1과 Point2의 값이 같아진다는 것은 하나의 vector가 비어있는 상태라는 것을 의미한다. 
// 만약 queue안에 음수가 포함된다면 다른 방법을 찾아야 하지만 주어진 queue는 양의 정수만 포함하기 때문에 CurrentTotal값만으로 파악이 가능하다.
