#include <iostream>
#include <algorithm>
using namespace std;

int weight[101];
int value[101];
int dp[101][100001];

int main() {

	int N, K;
	cin >> N>>K; //물품의 개수, 최대 무게 
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
		cin >> value[i];
	}

	for (int i = 1; i <= N; i++) { //물품의 인덱스(행)
		for (int j = 1; j <= K; j++) { //무게(열)
			if (j >= weight[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j-weight[i]] + value[i]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];

	return 0;
}