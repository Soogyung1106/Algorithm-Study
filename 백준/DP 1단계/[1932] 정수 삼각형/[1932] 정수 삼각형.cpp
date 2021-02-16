#include <iostream>
#include <algorithm>
using namespace std;

long long cost[500][500];
long long dp[500][500];
int N; //삼각형의 크기

long long getMaxCost() {
	dp[0][0] = cost[0][0];
	if (N == 1)  return dp[0][0];
	
	for (int i = 1; i < N; i++) { //행
		for (int j = 0; j <= i; j++) { //열
			//맨 앞
			if (j == 0) dp[i][j] = dp[i - 1][0] + cost[i][j];
			//맨 뒤
			else if (j == N - 1) dp[i][j] = dp[i - 1][j - 1] + cost[i][j];
			//가운데
			else dp[i][j] = max(dp[i - 1][j - 1] + cost[i][j], dp[i - 1][j] + cost[i][j]);
		}	
	}

	//dp[N-1][i] 중 최대값 찾기
	long long max = 0;
	for (int i = 0; i < N; i++)
		if (max < dp[N - 1][i]) max = dp[N - 1][i];

	return max;
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j <= i; j++) 
			cin >> cost[i][j];

	cout << getMaxCost();

	return 0;
}