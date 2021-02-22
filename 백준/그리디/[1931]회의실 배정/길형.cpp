#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int cmp(const pair<int, int> &a, const pair<int, int> &b) // 끝나는 시간이 같다면 시작시간이 늦은 것으로 정렬
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	vector<pair<int, int>> v; // 시작시간, 종료시간

	int n;
	int answer = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int start, end;

		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}

	sort(v.begin(), v.end(), cmp);

	int end = -1;

	for (int i = 0; i < n; i++)
	{
		if (v[i].first >= end) // 다음 회의의 시작시간이 이전 회의의 끝나는 시간보다 이후면
		{
			answer++; // 회의수 증가
			end = v[i].second; // 끝나는 시간 end에 현재 v[i]의 끝나는 시간을 넣어줌
		}
	}

	cout << answer << endl;

	return 0;
}
