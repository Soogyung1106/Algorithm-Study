#include <iostream>
using namespace std;

const int MAX = 1000000;
int arr[MAX];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N;i++) 
		cin >> arr[i];
	
	int main, sub;
	cin >> main >> sub;

	long long answer = 0;
	for (int i = 0; i < N; i++) {

		//메인 감독관 1명
		answer += 1;  
		arr[i] -= main;

		//부감독관
		if (0 <arr[i] && arr[i] <= sub) answer += 1; //3명을 20명이 감독할 때
		else if (arr[i] > sub) {
			answer += (arr[i] / sub);
			arr[i] %= sub; 
			if (0 < arr[i]) answer += 1;
		}
	}

	cout << answer;
	return 0;
}