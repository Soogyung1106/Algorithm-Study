#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	//입력
	int N, K; //동전 종류, 만들어야 하는 가치 합.
	cin >> N >> K;

	vector<int> money(N, 0);
	for (int i = 0; i < N; i++) 
		cin >> money[i];
	
	//내림차순 정렬
	reverse(money.begin(), money.end());

	int num = 0;
	for (int i = 0; i < N; i++) {
		if (K == 0) break;

		if (money[i] > K) continue;
		if (money[i] <= K) {
			num += K / money[i];
			K = K % money[i];
		}
	}

	cout << num;
	return 0;
}