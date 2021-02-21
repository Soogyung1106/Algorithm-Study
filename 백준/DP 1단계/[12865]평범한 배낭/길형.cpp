/*
<knapsack 이라는 유명한 dp문제의 유형>


Val(i, w) -> [1 ~ i]번째까지 물건에 대해, w무게까지 허용됐을 때의 최대 가치(VALUE)

Val(i, w) = Val(i-1, w-weight[i]) + value[i] -> i번째 짐(ITEM)을 담기 전 상태에서 i번째 물건(ITEM)을 담은 것


[조건]
w >= weight[i] // 현재 허용가능한 범위의 무게

[점화식]
Val(i, w) = (w >= weight[i]) ? max( Val(i-1,w), Val(i-1,w-weight[i])+value[i] ) : Val(i-1,w)
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 101
#pragma warning(disable:4996)

using namespace std;

int w[101]; // 무게
int v[101]; // 가치
int dp[101][100001];

int main(void)
{
	freopen("input.txt", "r", stdin);

	int N, K; // 물품의 수 N, 준서가 버틸 수 있는 무게 K

	cin >> N >> K;
	for (int i = 1; i <= N; i++) 
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= K; j++) 
		{
			if (j - w[i] >= 0) // i번째 물건을 넣을 수 있다면?
			{ 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]); // max(넣지 않을 때, 새로 넣을 때)
				
			}
			else // i번째 물건을 넣을 수 없다면, 배낭 용량은 같고 넣지 않았을 때의 값으로 초기화
			{ 
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];

	return 0;
}
