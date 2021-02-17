#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];
int N;
int DP[101];
int answer = 1;

int solution() {
	DP[0] = 1;
	for (int i = 1; i < N; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && DP[i] < DP[j] + 1) {
				DP[i] = DP[j] + 1;
			}
		}
		answer = max(answer, DP[i]);
	}
	return answer;
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int result = solution();
	cout << result << '\n';
	return 0;
}