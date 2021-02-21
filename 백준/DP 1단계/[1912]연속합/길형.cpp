#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 100000

using namespace std;

int number[MAX] = { 0, };
int dp[MAX] = { 0, };

int main(void)
{
	int n, i;

	cin >> n;

	for (i = 0; i < n; i++) 
	{
		cin >> number[i];
		dp[i] = number[i];
	}

	int maxSum = dp[0];

	for (i = 1; i < n; i++) 
	{
		dp[i] = max(dp[i], dp[i - 1] + number[i]); // dp[i]는 0 ~ (i-1)까지의 max(최대합 dp[i]에 저장되어 있는 값, dp[i-1] + number[i]의 값)

		if (dp[i] > maxSum) 
		{
			maxSum = dp[i];
		}
	}

	cout << maxSum << endl;

	return 0;
}
