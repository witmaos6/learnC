// 2022 KAKAO TECH INTERNSHIP 성격 유형 
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> Score = { 0,3,2,1,0,1,2,3 };
vector<vector<char>> Type = { {'R','T'},{'C','F'},{'J','M'},{'A','N'} };
int ZeroIndex = 4;

string solution(vector<string> survey, vector<int> choices);
unordered_map<char, int> CalcluateScore(vector<string>& survey, vector<int>& choices);
string ReturnTypeResult(unordered_map<char, int>& Score);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	return 0;
}

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";

	unordered_map<char, int> Mapping = CalcluateScore(survey, choices);

	return ReturnTypeResult(Mapping);
}

unordered_map<char, int> CalcluateScore(vector<string>& survey, vector<int>& choices)
{
	unordered_map<char, int> Mapping;

	int SurveySize = static_cast<int>(survey.size());

	for (int i = 0; i < SurveySize; i++)
	{
		int SelectScore = choices[i];
		if (SelectScore > ZeroIndex)
		{
			Mapping[survey[i][1]] += Score[SelectScore];
		}
		else if (SelectScore < ZeroIndex)
		{
			Mapping[survey[i][0]] += Score[SelectScore];
		}
		else if (SelectScore == ZeroIndex)
		{
			Mapping[survey[i][0]] += 0;
			Mapping[survey[i][1]] += 0;
		}
	}
	return Mapping;
}


string ReturnTypeResult(unordered_map<char, int>& Score)
{
	string TypeResult = "";
	for (vector<char>& c : Type)
	{
		int Score1 = 0;
		int Score2 = 0;

		if (Score.find(c[0]) != Score.end())
		{
			Score1 = Score[c[0]];
		}
		if (Score.find(c[1]) != Score.end())
		{
			Score2 = Score[c[1]];
		}
		if (Score1 >= Score2)
		{
			TypeResult += c[0];
		}
		else
		{
			TypeResult += c[1];
		}
	}
	return TypeResult;
}
// 문제가 간단해서 사이트에서 바로 풀었는데 오타가 많이 난다. 어떤 식으로 풀어야할지 감은 바로 잡히는데 표현이 어렵다. 
