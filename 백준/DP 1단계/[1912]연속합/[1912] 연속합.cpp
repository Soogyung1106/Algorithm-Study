/*
경우의 수 4가지 (이전까지 더한 연속합, 현재 더해야 할 수)
(+, +) -> (o)
(-, +) -> (x) 굳이 이전것을 더해봤자 값을 값을 깎으므로 다시 시작
(+, -) -> (o) 더했는데 현재 값을 양수로 키워준다면 더해도 됨.(그 다음 값에 더해줄 때 도움되므로)
(-, -) -> (x) 음수인데 음수값까지 더해서 값을 더 작아지게 할 필요 없음. 
*/
#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main() {
	
	//입력 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) //dp 초기화
		cin >> dp[i];
	

	int max = dp[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] > 0 && dp[i - 1] + dp[i] > 0)
			dp[i] += dp[i - 1]; //점화식

		if (max < dp[i]) max = dp[i];
	}

	cout << max;
	
	return 0;
}