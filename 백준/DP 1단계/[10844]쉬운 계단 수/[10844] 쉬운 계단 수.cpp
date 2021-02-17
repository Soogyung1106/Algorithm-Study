/* 점화식 
행: 숫자의 길이(N), 열: 맨끝 자리에 오는 숫자 
dp[i][j] = i길의 숫자에서 맨 끝에 j가 오는 경우의 수 

\ 0|1|2|3|4|5|6|7|8|9
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
1|0|1|1|1|1|1|1|1|1|1
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
2|1|1|2|2|2|2|2|2|2|1
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
3|1|3|4|4|4|4|4|4|3|2

*/

#include <iostream>
using namespace std;
int dp[101][10]; //최대 100자리 수(N) 
int N;

int solution() {

	//기저 조건 초기화
	dp[1][0] = 0;
	for (int endNum = 1; endNum <= 9; endNum++) dp[1][endNum] = 1;

	//점화식
	for (int len = 2; len <= N; len++) { //길이가 2부터 N일 때까지 Bottom-Up
		//끝 자리 수가 0일 경우
		dp[len][0] = dp[len - 1][1] % 1000000000;

		//끝 자리 수가 1~8일 경우
		for (int endNum = 1; endNum <= 8; endNum++)
			dp[len][endNum] = (dp[len - 1][endNum - 1] + dp[len - 1][endNum + 1]) % 1000000000;

		//끝 자리 수가 9일 경우
		dp[len][9] = dp[len - 1][8] % 1000000000;
	}

	//길이가 N일 경우 끝자리가 0~9인 모든 경우의 더하기
	int answer = 0;
	for (int endNum = 0; endNum <= 9; endNum++) answer = (answer + dp[N][endNum]) % 1000000000;
	return answer;
}

int main() {
	
	cin >> N;

	cout << solution();

	return 0;
}

