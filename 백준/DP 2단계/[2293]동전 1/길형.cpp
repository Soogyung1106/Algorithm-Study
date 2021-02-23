#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)
int coin[101];
int d[10001];

using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) 
	{
		cin >> coin[i];
	}

	d[0] = 1; // 동전을 아무것도 안쓰는 경우.

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= k; j++) 
		{
			if (j - coin[i] >= 0)
			{
				d[j] += d[j - coin[i]];
				/*
				dp[j] = dp[j](기존의 동전 종류를 이용해 k를 만드는 경우의 수) + dp[j - coins[i]](새 동전 종류 사용하는 경우 추가)

				(1, 2, 5) 10

				1 2 3 4 5 6 7 8 9 10
				1 1 1 1 1 1 1 1 1  1 => 1원만 쓰는 경우
				0 1 0 1 0 1 0 1 0  1 => 2원만 쓰는 경우
				0 0 0 0 1 0 0 0 0  1 => 5원만 쓰는 경우

				0 - X+X+X
				1 - 1
				2 - 1+1, 2
				3 - 1+1+1, 1+2
				4 - 1+1+1+1, 1+1+2, 2+2
				5 - 1+1+1+1+1, 1+1+1+2, 5

				coin[3] = {0, 1, 2, 5};
				d[0] = 1;

				(i=1, coin[1] = 1)
				d[1] += d[0] >> 0 + 1 = 1
				d[2] += d[1] >> 0 + 1 = 1
				d[3] += d[2] >> 0 + 1 = 1
				d[4] += d[3] >> 0 + 1 = 1
				.
				.
				.
				d[10] += d[9] >> 0 + 1 = 1

				(i=2, coin[2] = 2)
				d[0] = 1
				d[1] = d[1] + d[-1] >> 1
				d[2] = d[2] + d[0] >> 1 + 1 = 2
				d[3] = d[3] + d[1] >> 1 + 1 = 2
				d[4] = d[4] + d[2] >> 1 + 2 = 3
				d[5] = d[5] + d[3] >> 1 + 2 = 3
				d[6] = d[6] + d[4] >> 1 + 3 = 4
				d[7] = d[7] + d[5] >> 1 + 3 = 4
				d[8] = d[8] + d[6] >> 1 + 4 = 5
				d[9] = d[9] + d[7[ >> 1 + 4 = 5
				d[10] = d[10] + d[8] >> 1 + 5 = 6

				(i=3, coin[3] = 5)
				d[1] ~ d[4] >> X
				d[5] = d[5] + d[0] >> 3 + 1 = 4
				d[6] = d[6] + d[1] >> 4 + 1 = 5
				d[7] = d[7] + d[2] >> 4 + 2 = 6
				d[8] = d[8] + d[3] >> 5 + 2 = 7
				d[9] = d[9] + d[4] >> 5 + 3 = 8
				d[10] = d[10] + d[5] >> 6 + 4 = 10
				*/
			}
		}
	}

	cout << d[k] << endl;

	return 0;
}
