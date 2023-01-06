#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

const char Gate = 'g';
const char Summit = 's';
const char Rest = 'r';

struct Vertex
{
	int Number;
	int W;
	Vertex() : Number(0), W(0) {}
	Vertex(int next, int w) : Number(next), W(w) {}
};

struct Compare
{
	bool operator()(const Vertex& v1, const Vertex& v2)
	{
		if (v1.W == v2.W)
		{
			return v1.Number > v2.Number;
		}
		return v1.W > v2.W;
	}
};

vector<int> answer = { 0, 10000001 };
vector<char> VertexInfor;
vector<int> EdgeIntensity;
unordered_map<int, vector<Vertex>> Mountain;
priority_queue<Vertex, vector<Vertex>, Compare> Traverse;

vector<char> SetTable(int& n, vector<int>& gates, vector<int>& summits)
{
	vector<char> Table(n + 1, Rest);

	for (int& gate : gates)
	{
		Table[gate] = Gate;
	}
	for (int& summit : summits)
	{
		Table[summit] = Summit;
	}
	return Table;
}

unordered_map<int, vector<Vertex>> SetMountain(vector<vector<int>>& paths)
{
	unordered_map<int, vector<Vertex>> mountain;

	for (vector<int>& path : paths)
	{
		int P1 = path[0];
		int P2 = path[1];
		int w = path[2];

		Vertex V1(P1, w);
		Vertex V2(P2, w);

		if (VertexInfor[P1] == Rest && VertexInfor[P2] == Rest)
		{
			mountain[P1].push_back(V2);
			mountain[P2].push_back(V1);
		}
		else if (VertexInfor[P1] != Summit && VertexInfor[P2] != Gate)
		{
			mountain[P1].push_back(V2);
		}
		else if (VertexInfor[P2] != Summit && VertexInfor[P1] != Gate)
		{
			mountain[P2].push_back(V1);
		}
	}

	return mountain;
}

void DP()
{
	while (!Traverse.empty())
	{
		Vertex CurrentV = Traverse.top();
		Traverse.pop();

		if(EdgeIntensity[CurrentV.Number] < CurrentV.W)
		{
			continue;
		}
		for (Vertex& NextV : Mountain[CurrentV.Number])
		{
			int Temp = max(NextV.W, CurrentV.W);

			if(EdgeIntensity[NextV.Number] > Temp)
			{
				EdgeIntensity[NextV.Number] = Temp;
				Traverse.push(Vertex(NextV.Number, Temp));
			}	
		}
	}
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
	VertexInfor = SetTable(n, gates, summits);
	Mountain = SetMountain(paths);
	EdgeIntensity.resize(n + 1, 10000001);

	for (int& gate : gates)
	{
		Traverse.push(Vertex(gate, 0));
		EdgeIntensity[gate] = 0;
	}

	DP();

	sort(summits.begin(), summits.end());

	for(int& summit : summits)
	{
		if(EdgeIntensity[summit] < answer[1])
		{
			answer[1] = EdgeIntensity[summit];
			answer[0] = summit;
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<int>> paths = { {1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1} };
	vector<int> gates = { 1, 3 };
	vector<int> summits = { 5 };
	vector<int> answer = solution(6, paths, gates, summits);

	for (int& i : answer)
	{
		cout << i << ' ';
	}

	return 0;
}

// DFS로 시도했을 때 시간초과가 발생하여 DP로 전환했다.
