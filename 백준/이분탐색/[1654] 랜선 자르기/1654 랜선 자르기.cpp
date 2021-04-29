//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
int K, N;
long long ans;

int binary_search() {
	long long start = 1, end = v[v.size() - 1];
	long long mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		//랜선 길이가 mid일 경우
		int cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += v[i] / mid;
		}

		//랜선의 최대 길이를 구하는게 목표
		if (cnt >= N) {
			ans = max(ans, mid);
			start = mid + 1;
		}
		else //작 
			end = mid - 1;
	}

	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input1.txt", "r", stdin);
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	
	cout << binary_search() << '\n';

	return 0;
}