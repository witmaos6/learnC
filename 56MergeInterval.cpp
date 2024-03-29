// {start, end} 로 이루어진 배열이 주어지면 오버랩 되는 부분을 합친 후 반환하라
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals);
	vector<vector<int>> MergeSpace(vector<vector<int>>& intervals);
	void Print2DVector(vector<vector<int>>& intervals);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<int>>Intervals = {
		{2,4},{1,3}
	};
	Solution solution;
	Intervals = solution.merge(Intervals);
	solution.Print2DVector(Intervals);

	return 0;
}

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals)
{
	int IntervalsSize = static_cast<int>(size(intervals));
	sort(intervals.begin(), intervals.end()); // intervals[row][0] 값을 기준으로 정렬
	for (int row = 0; row < IntervalsSize - 1; row++) 
	{
		if (intervals[row][1] >= intervals[row + 1][0])
		{
			if (intervals[row][1] <= intervals[row + 1][1])
			{
				intervals[row][1] = intervals[row + 1][1];
			}
			intervals.erase(intervals.begin() + row + 1);
			row--;
			IntervalsSize--;
		}
	}
	return intervals;
}

vector<vector<int>> Solution::MergeSpace(vector<vector<int>>& intervals)
{
	int IntervalSize = static_cast<int>(size(intervals));
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> NonOverlapping;
	NonOverlapping.reserve(IntervalSize);
	NonOverlapping.emplace_back(intervals[0]);
	for (int i = 1; i < IntervalSize; i++)
	{
		if (NonOverlapping.back()[1] >= intervals[i][0])
		{
			NonOverlapping.back()[1] = max(NonOverlapping.back()[1], intervals[i][1]);
		}
		else
		{
			NonOverlapping.emplace_back(intervals[i]);
		}
	}
	return NonOverlapping;
}

void Solution::Print2DVector(vector<vector<int>>& intervals)
{
	for (vector<int>& row : intervals)
	{
		for (int& col : row)
		{
			cout << col << ' ';
		}
		cout << '\n';
	}
}
// merge의 시간복잡도는 O(NlogN)+O(N^2)이고 MergeSpace의 시간복잡도는 O(NlogN)+O(N)이다.
// mewge는 erase연산을 하기때문에 worst case에서 연산시간이 더 걸린다.
