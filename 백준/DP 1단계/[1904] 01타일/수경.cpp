#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int DP(int n) {
	if (n == 1) return memo[1] = 1;
	if (n == 2) return memo[2] = 2;
	
	if (memo[n] != 0) return memo[n] % 15746;
	else return memo[n] = (DP(n - 1) + DP(n - 2))% 15746;
}


int main() {

	int N;
	cin >> N;

	memo.resize(N+1, 0); 
	cout << DP(N);

	return 0;
}
