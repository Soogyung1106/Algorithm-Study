#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define MAX 18
#define endl "\n"
using namespace std;

typedef pair<int, int> PAIR;

int dp[MAX];
vector<PAIR> day(MAX); // { 소요시간, 수입}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> day[i].first >> day[i].second;

	for (int i = n; i > 0; i--)
	{
		i + day[i].first;

		if (i + day[i].first > n + 1) // 현재 일 + 소요 일수가 퇴사일을 넘어버리는 경우
		{
			dp[i] = dp[i + 1]; // day[i] 상담을 안함
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[i + day[i].first] + day[i].second);
		}
	}

	cout << dp[1] << '\n';

	return 0;
}
