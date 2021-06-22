#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <set>
#define endl "\n"

using namespace std;

string str;
bool visit[201];
bool str_visit[201];
set<string> answer;
vector<pair<int, int>> v;

void dfs(int cnt, int idx) 
{
	if (cnt >= 1) 
	{
		string s = "";
		for (int i = 0; i < str.size(); i++) 
		{
			if (str_visit[i]) continue;
			s += str[i];
		}
		answer.insert(s);
	}

	for (int i = idx; i < v.size(); i++) 
	{
		if (visit[i]) continue;
		visit[i] = true;
		str_visit[v[i].first] = true;
		str_visit[v[i].second] = true;
		dfs(cnt + 1, idx + 1);
		visit[i] = false;
		str_visit[v[i].first] = false;
		str_visit[v[i].second] = false;
	}
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> str;
	stack<int> bracket;

	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] == '(') 
		{
			bracket.push(i);
		}
		else if (str[i] == ')') 
		{
			v.push_back({ bracket.top(), i });
			bracket.pop();
		}
	}

	dfs(0, 0);

	for (auto s : answer)
	{
		cout << s << endl;
	}

	return 0;
}
