#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

/*
3잔 연속으로 마실 수 없음.
모두 마신 후 원래 자리에 놔둬야함

3잔단위로 끊으면 

0 1 1+ MAX(1 0 1 or 0 1 1)

1 0 1 + MAX(1 0 1 or 0 1 1)

1 1 0 + MAX(1 1 0 or 1 0 1 or 0 1 1) 

=>

N번째 dp[N]은 해당 위치에서의 가장 큰 값들을 저장하며 메모제이션 하는 배열
*/
int main(void)
{
	int N = 0;

	cin >> N;

	vector<int> wine(N+1,0);
	vector<int> dp(N+1,0);

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;

		cin >> wine[i];
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= N; i++)
	{
		dp[i] = wine[i] + max(dp[i - 2], wine[i - 1] + dp[i - 3]);
        dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[N] << endl;

	return 0;
}
