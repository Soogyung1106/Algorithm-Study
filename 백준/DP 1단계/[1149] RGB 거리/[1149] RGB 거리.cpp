#include <iostream>
#include <algorithm>
using namespace std;

int cost[1000][3];
int dp[1000][3];
int N;

int getMinCost() { 
	//bottom-up 방식으로 구현
	dp[0][0] = cost[0][0]; dp[0][1] = cost[0][1]; dp[0][2] = cost[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1] + cost[i][0], dp[i - 1][2] + cost[i][0]);
		dp[i][1] = min(dp[i - 1][0] + cost[i][1], dp[i - 1][2] + cost[i][1]);
		dp[i][2] = min(dp[i - 1][0] + cost[i][2], dp[i - 1][1] + cost[i][2]);
	}

	return min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2]; //빨, 초, 파

	cout << getMinCost(); //dp

	return 0;
}