/*
수열 A = {10, 20, 10, 30, 20, 50}

10 20 30 50

1. 증가하는 수열일 것.
2. n-1, n, n+1의 차가 제일 큰 것.

문제가 이해가 잘 안되는데...

수열의 n+d 의 등차수열에서 d가 큰 것을 찾으라는 것인지...

d가 양의 정수인 수열을 부분 수열에서 가장 긴 수열을 찾으라는 것인지?

아래 후자인 것 같음.
*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1001

using namespace std;

int main()
{
	int N; 
	int number[MAX];
	int dp[MAX];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> number[i];
	}

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (number[j] < number[i] && dp[j] >= dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
	} 
	
	int max = -1;

	for (int i = 0; i < N; i++)
	{
		if (max < dp[i]) max = dp[i];
	}

	cout << max;

	return 0;
}

