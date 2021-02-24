#include <iostream>
#include <cstring>
using namespace std;

int n;
int mat[500][2];
int cache[500][500];

int solve(int le, int ri) { //[le, ri]의 범위에서의 최솟값
	if (le == ri) return 0;

	int& ret = cache[le][ri];
	if (ret != -1) return ret;
	ret = 987654321;
	
	for (int i = le; i < ri; i++) {
		ret = min(ret, solve(le, i) + solve(i + 1, ri) + mat[le][0] * mat[i][1] * mat[ri][1]);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mat[i][0] >> mat[i][1];
	memset(cache, -1, sizeof(cache));
	cout << solve(0, n - 1)<<'\n';
	return 0;
}
