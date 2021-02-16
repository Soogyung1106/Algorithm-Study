#include <iostream>
#include <algorithm>
using namespace std;

long long cost[301];
long long dp[301];
int N; //계단의 개수

long long getMaxCost(int n) {

	dp[0] = 0; dp[1] = cost[1]; dp[2] = cost[1] + cost[2];

	if (n < 3) return dp[n]; //예외처리

	for (int i = 3; i <= n; i++) 
		dp[i] = max(dp[i - 2] + cost[i], dp[i - 3] + cost[i - 1] + cost[i]);
	
	return dp[n];
}

int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> cost[i];

	cout << getMaxCost(N);

	return 0;
}