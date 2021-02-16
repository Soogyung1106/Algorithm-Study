#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
	int N = 0;

	cin >> N;

	vector<int> stair(N+1,0);
	vector<int> dp(N+1,0);

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;

		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(stair[i] + stair[i - 1] + dp[i - 3], stair[i] + dp[i - 2]);
	}

	cout << dp[N] << endl;

	return 0;
}
