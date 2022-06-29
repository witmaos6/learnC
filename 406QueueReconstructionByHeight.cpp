// people[i]는 people의 키 hi와 자신의 앞에 있는 people중 자신보다 크거나 같은 people의 수 ki로 이루어져있다.
// 올바르게 정렬하라
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	static bool compare(vector<int>& v1, vector<int>& v2);
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people); //O(NlogN)+O(N^2)
	void Print2DVector(const vector<vector<int>>& people);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	vector<vector<int>> People = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
	Solution solution;
	People = solution.reconstructQueue(People);
	solution.Print2DVector(People);
}

vector<vector<int>> Solution::reconstructQueue(vector<vector<int>>& people)
{
	int PeopleSize = (int)people.size();
	sort(people.begin(), people.end(), compare); // O(NlogN)

	vector<vector<int>> result(PeopleSize, vector<int>());
	for (int i = 0; i < PeopleSize; i++) // O(N^2)
	{
		int count = 0;
		int j;
		for (j = 0; j < PeopleSize; j++)
		{
			if (result[j].empty())
			{
				if (count == people[i][1]) break;
				count++;
			}
		}
		result[j] = people[i];
	}
	return result;
}

bool Solution::compare(vector<int>& v1, vector<int>& v2)
{
	if (v1[0] != v2[0]) return v1[0] < v2[0]; // 키 순서로 오름차순
	else return v1[1] > v2[1]; // 키가 같다면 ki의 내림차순
}

void Solution::Print2DVector(const vector<vector<int>>& people)
{
	for (vector<int> e : people)
	{
		cout << e[0] << " " << e[1] << '\n';
	}
}
// hi 혹은 ki를 기준으로 정렬한 뒤 다시 한번더 정렬을 해야됐는데 이부분이 조금 까다로웠다.
// 이진 탐색을 이용해서 최적화도 가능할 것 같은데 조금 더 생각해봐야겠다.
