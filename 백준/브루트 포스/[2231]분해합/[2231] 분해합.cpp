#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long getSumOfN(int num) {
	long long sum = num;
	while (num != 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

long long getN(int N) {
	//N이 몇 자릿수인지 구하기 
	long long cnt = 0;
	while (N!=0) {
		N /= 10;
		cnt++;
	}
	return cnt;
}

int main() {

	//분해합 입력
	int N;
	cin >> N;  
	
	long long start = N - 9 * getN(N); //자리에 올 수 있는 최대수는 9
	
	//i의 분해합이 N가 같은지 판단해 i가 생성자가 될 수 있는지 판단 
	for (long long i = start; i < N; i++) {
		if (getSumOfN(i) == N) {
			cout << i;
			return 0;
		}
	}
	
	cout << 0;
	return 0;
}