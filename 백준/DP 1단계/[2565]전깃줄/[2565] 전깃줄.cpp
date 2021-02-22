#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	//입력
	int N;
	cin >> N;

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int first, second;
		cin >> first >> second;
		v.push_back({ first, second });
	}
	

	//전깃줄 번호(first) 기준 정렬
	sort(v.begin(), v.end()); 
	
	
	//맨 끝이 v[i].second일 때 증가하는 부분 수열 최대 길이
	vector<int> dp(N+1, 1);
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	//최소로 제거해야 하는 전선 개수
	int max = *max_element(dp.begin(), dp.end());
	int min = N - max;
	cout << min;

	return 0;
}