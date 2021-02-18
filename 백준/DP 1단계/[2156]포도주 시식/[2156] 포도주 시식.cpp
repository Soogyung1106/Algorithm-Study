/* 점화식
dp[n] = max(dp[n-3]+wine[n-1]+wine[n], dp[n-2]+wine[n]) //n번쨰 포도주를 반드시 마신 경우
dp[n] = max(dp[n], dp[n-1]); //n번째 포도주를 안 마신 경우
*/

#include <iostream>
#include <algorithm>
using namespace std;

long long dp[10001];
long long wine[10001];
int N;

long long getMaxWine() {
	dp[1] = wine[1]; dp[2] = wine[1] + wine[2];
	if (N < 3) return dp[N];

	//점화식
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]); //n번쨰 포도주를 반드시 마신 경우
		dp[i] = max(dp[i], dp[i - 1]); //n번째 포도주를 안 마신 경우가 더 클수도 있기 때문에
	}

	return dp[N];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> wine[i];

	cout<<getMaxWine();

	return 0;
}