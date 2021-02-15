#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int dp[41] = {1, 0};

int Fibo(int n) {
	if (n == 0) return dp[0];
	else if (n == 1) return dp[1];
	else if (dp[n] > 0) return dp[n]; //포인트
	else return dp[n] = Fibo(n - 1) + Fibo(n - 2);

}

int main() {

	/* 규칙
	0과 1의 개수: An = An-1 + An-2
	(0 기저조건 -> A0 = 1, A1 = 0)
	(1 기저조건 -> A0 = 0, A1 = 1)
	*/
	
	//입력
	int T;
	cin >> T;

	dp[0] = 1; dp[1] = 0;
	vector<tuple<int, int>> answer;
	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		
		//Top-Down
		answer.push_back({ Fibo(num), Fibo(num+1) });
	}

	//출력
	for (auto elem : answer)
		cout << get<0>(elem) << " " << get<1>(elem) << endl;

	return 0;
}
