#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

int arr[510][2];
int dp[510][510];

int main(void)
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	
	cin >> n;

	for (int i = 1; i <= n; i++) 
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 1; i < n; i++) 
	{
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}

	for (int m = 2; m <= n; m++) 
	{ 
		for (int i = 1; i <= n - m; i++) 
		{ 
			int j = i + m;
			/*
			123 234 345 456 ... 이런식으로 작은 범위의 행렬의 곱 중 최소값을 구해가면서 캐싱
			*/

			for (int k = i; k < j; k++)
			{
				int res = dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1];
				if (!dp[i][j] || dp[i][j] > res) dp[i][j] = res;
			}
		}
	}
	cout << dp[1][n];

	return 0;
}

/*
(Example - 블로그 참고)
20x1, 1x30, 30x10, 10x10

((A*B)*C)*D) = (20*1*30) + (20*30*10) + (20*10*10) = 8,600
A*(B*(C*D)) = (30*10*10) + (1*30*10) + (20*1*10) = 3,500
(A*B)*(C*D) = (20*1*30) + (30*10*10) + (20*30*10) = 9,600
(A*((B*C)*D) = (1*30*10) + (1*10*10) + (20*1*10) = 600

DP : 큰 문제를 작은 것으로 쪼개면서 Memorization을 통해 문제를 해결하는 것 기억하자!

dp[i][j] => 행렬i부터 행렬j 까지를 곱할 때 필요한 곱셈의 최소횟수
dp[i][j] = dp[i][k] + dp[k+1][j] + 곱셈 비용 의 최솟값.

*/
