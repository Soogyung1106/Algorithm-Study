#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {

	//입력
	int n;
	cin >> n;
	vector<pair<int, int>> people(n);
	for (int i = 0; i < n; i++) {
		cin >> people[i].first >> people[i].second;
	}

	//등수 탐색
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (people[i].first < people[j].first && people[i].second < people[j].second)
				cnt++;
		}
		cout << cnt + 1 << " ";
	}

	return 0;
}