#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <sstream>
using namespace std;

class Solution
{
public:
	vector<int> solution(vector<string> id_list, vector<string> report, int k);
	void GetID(const string& s, string& userID, string& reportID);
	void IDMapping(map<string, int>& Mapping, const vector<string>& IDList);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution geon;
	vector<string> IdList = { "muzi", "frodo", "apeach", "neo" };
	vector<string> Report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi","apeach muzi" };
	int k = 2;

	//case 2
	vector<string> IdList2 = { "con", "ryan" };
	vector<string> Report2 = { "ryan con", "ryan con", "ryan con", "ryan con" };
	int k2 = 3;

	vector<int> Result = geon.solution(IdList, Report, k);

	for(int& i : Result)
	{
		cout << i << '\n';
	}

	return 0;
}

vector<int> Solution::solution(vector<string> id_list, vector<string> report, int k)
{
	vector<int> answer(id_list.size());
	unordered_map<string, set<string>> FromReport;
	unordered_map<string, int> ReceiveReport;
	map<string, int> IdListMappingAnswer;

	IDMapping(IdListMappingAnswer, id_list); // O(NlogN) N == id_list.size()

	for (string& s : report) // O(M) M == report.size()
	{
		stringstream ID(s);
		string UserId, ReportId;
		ID >> UserId >> ReportId;
		if (FromReport[ReportId].find(UserId) == FromReport[ReportId].end()) // O(logF) F==find()
		{
			FromReport[ReportId].insert(UserId);
			ReceiveReport[ReportId]++;
		}
	}

	for (auto& e : ReceiveReport) // O(N^2)
	{
		if (e.second >= k)
		{
			for (const string& s : FromReport[e.first])
			{
				answer[IdListMappingAnswer[s]]++;
			}
		}
	}

	return answer;
}

void Solution::IDMapping(map<string, int>& Mapping, const vector<string>& IDList)
{
	for (size_t i = 0; i < IDList.size(); i++)
	{
		Mapping[IDList[i]] = static_cast<int>(i);
	}
}