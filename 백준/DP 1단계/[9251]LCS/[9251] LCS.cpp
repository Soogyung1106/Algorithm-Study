#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;

	for (int i = 0; i < s1.size(); i++) { //행
		for (int j = 0; j < s2.size(); j++) { //열
			if (s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j] + 1;
			else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		}
	}

	cout << dp[s1.size()][s2.size()];
	
	return 0;
}