#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	long long N;
	cin >> N;

	vector<long long> dp(N + 1, 0); //dp[1] = 0

	for (long long i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[N];
	return 0;
}
