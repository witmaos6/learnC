#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	static bool compare(vector<int>& v1, vector<int>& v2);
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people);
	void Update(vector<int>& Person, const int& begin);
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
	sort(people.begin(), people.end(), compare);

	vector<vector<int>> result(PeopleSize, vector<int>());
	for (int i = 0; i < PeopleSize; i++)
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
	if (v1[0] != v2[0]) return v1[0] < v2[0];
	else return v1[1] > v2[1];
}

void Solution::Print2DVector(const vector<vector<int>>& people)
{
	for (vector<int> e : people)
	{
		cout << e[0] << " " << e[1] << '\n';
	}
}
