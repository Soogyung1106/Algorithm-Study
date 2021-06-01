#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <stack>
#define endl "\n"

using namespace std;

int N;

bool comp(pair<string, int> a, pair<string, int> b)
{
	if (a.first[0] != b.first[0])
	{
		return a.first[0] < b.first[0];
	}

	return atoi(a.first.substr(2, a.first.size() - 2).c_str()) < atoi(b.first.substr(2, b.first.size() - 2).c_str()); // c.str() string -> char 바꿔주는 메소드.
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
	cin >> N;

	N = 5 * N;

	vector<pair<string, int>> v(N);
	vector<int> num(N);
	stack<int> line, wait; // 대기줄, 입장 대기줄

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first; // 티켓 String
		v[i].second = i; // 입력된 순서, 인덱스
	}

	sort(v.begin(), v.end(), comp); // 티켓 순서대로 정렬.

	for (int i = 0; i < N; ++i)
	{
		num[v[i].second] = i;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		line.push(num[i]);
	}

	for (int i = 0; i < N; i++)
	{
		if (!wait.empty() && wait.top() == i)
		{
			wait.pop();
			continue;
		}

		bool in = false;
		
		while (!line.empty())  // 대기줄이 다 빌 때까지 반복, 대기줄이 다 비었는데 입장 대기줄이 빠지지 않는 다면 false, 계속 빠진다면 true;
		{
			if (line.top() != i) // 대기줄 -> 입장 대기줄
			{
				wait.push(line.top());
				line.pop();
			}
			else // 대기줄 -> 입장 대기줄 -> 바로 입장
			{
				line.pop();
				in = true;
				break;
			}
		}

		if (!in) 
		{
			cout << "BAD" << endl;

			return 0;
		}
	}

	cout << "GOOD" << endl;

	return 0;
}
