#include <iostream>
#include <vector>
using namespace std;

long long memo[101] = {0, 1, 1, 1, 2};

long long P(int N) { //Bottom-Up

	if (N < 5) return memo[N];

	for (int i = 5; i <= N; i++) 
		memo[i] = memo[i - 1] + memo[i - 5];

	return memo[N];
}


int main() {
	
	//입력
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout<<P(N)<<endl;
	}

	return 0;
}
