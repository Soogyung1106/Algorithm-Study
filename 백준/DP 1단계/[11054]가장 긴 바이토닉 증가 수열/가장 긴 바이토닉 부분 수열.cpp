#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
dpIn[i] = arr[i]가 끝에 올 경우 "증가하는 최대 수열"의 길이
dpDe[i] = arr을 역순으로 뒤집었을 때, arr[i]가 끝에 올 경우 "증가하는 최대 수열"의 길이
*/

int main() {
	
	int N;
	cin >> N;
	
	vector<int> arr(N, 0);
	vector<int> dpIn(N, 1);
	vector<int> dpDe(N, 1);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	//증가하는 부분 수열
	for (int i = 0; i < N; i++) { //arr[i]가 가장 끝에 오는 경우
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dpIn[j] + 1 > dpIn[i]) //숫자 비교 
				dpIn[i] = dpIn[j] + 1; //갱신
		}
	}
	
	reverse(arr.begin(), arr.end());

	//증가하는 부분 수열
	for (int i = 0; i < N; i++) { //arr[i]가 가장 끝에 오는 경우
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dpDe[j] + 1> dpDe[i]) //숫자 비교 
				dpDe[i] = dpDe[j] + 1; //갱신
		}
	}
	
	int max = 0;
	for (int i = 0; i < N; i++)
		if (max < dpIn[i] + dpDe[N-1-i]) max = dpIn[i] + dpDe[N - 1 - i];
	
	cout << max - 1;
	
	
	return 0;
}