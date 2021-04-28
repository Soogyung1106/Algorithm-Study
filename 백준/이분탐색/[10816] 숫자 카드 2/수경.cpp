//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

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
		cout << upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x) << " ";
	}
	return 0;
}
