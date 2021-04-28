//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int upper_binary(int x) { //초과

	int start = 0, end = v.size() - 1;
	int mid = 0;
	
	while (start < end) {

		mid = (start + end) / 2;

		if (v[mid] > x)
			end = mid;
		else 
			start = mid + 1;
	}

	return end;
}

int lower_binary(int x) { //이상

	int start = 0, end = v.size() - 1;
	int mid = 0;

	while (start < end) {

		mid = (start + end) / 2;

		if (v[mid] >= x) 
			end = mid;
		else 
			start = mid + 1;
	}

	return end;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input1.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;

		int upper = upper_binary(x);
		int lower = lower_binary(x);
		if (upper == N-1 && v[N-1] == x) upper++;
		
		cout << upper-lower << " ";
	}
	return 0;
}
