// searchWord가 주어질 때 products에서 seachWord.substr(0, ~searchWodr.size()) 와 일치하는 string 값을 최대 3개까지 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> suggestedProductsIteratorSolution(vector<string>& products, string searchWord);
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord);
	vector<string> SearchEachSubstr(const vector<string>& products, const string& Substr);
	void PrintSDVector(vector<vector<string>>& result);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	vector<string> Products = { "mobile","mouse","moneypot","monitor","mousepad" };
	string SearchWord = "mouse";

	Solution solution;
	vector<vector<string>> SearchResult = solution.suggestedProducts(Products, SearchWord);
	solution.PrintSDVector(SearchResult);

	return 0;
}

vector<vector<string>> Solution::suggestedProductsIteratorSolution(vector<string>& products, string searchWord)
{
	vector<vector<string>> SearchResult;
	sort(products.begin(), products.end()); // O(NlogN) N==products.size()
	string type = "";
	for (char& c : searchWord)
	{
		type += c; //O(M) M==searchWord.size()
		vector<string>::iterator LeftPoint = lower_bound(products.begin(), products.end(), type); //O(logN)
		vector<string>::iterator RightPoint = upper_bound(products.begin(), products.end(), type + '~'); // O(logN)
		if (LeftPoint == RightPoint)
		{
			break;
		}
		SearchResult.emplace_back(LeftPoint, min(LeftPoint + 3, RightPoint));
	}
	while (SearchResult.size() != searchWord.size())
	{
		SearchResult.push_back({});
	}

	return SearchResult;
}

vector<vector<string>> Solution::suggestedProducts(vector<string>& products, string searchWord)
{
	vector<vector<string>> SearchResult;
	sort(products.begin(), products.end()); // O(NlogN) N==products.size()
	string type = "";
	for (char& c: searchWord) // O(M) M== searchWord.size()
	{
		type += c;
		SearchResult.push_back(SearchEachSubstr(products, type));
	}

	return SearchResult;
}

vector<string> Solution::SearchEachSubstr(const vector<string>& products, const string& Substr) // O(N)
{
	vector<string> EachResult;
	for (string product : products)
	{
		if (product.substr(0, Substr.size()) == Substr)
		{
			EachResult.push_back(product);
			if (EachResult.size() == 3)
			{
				break;
			}
		}
	}
	return EachResult;
}


void Solution::PrintSDVector(vector<vector<string>>& result)
{
	for (int i = 0; i < (int)result.size(); i++)
	{
		for (int j = 0; j < (int)result[i].size(); j++)
		{
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}
// 첫번째 풀이는 O(NlogN) + O(M*N)의 시간이 걸렸다.
// 두번째 풀이는 Iterator를 사용해서 풀었다. O(NlogN) + O(M*(logN)^2)
// 두번째 풀이가 활실히 더 빠르다.
