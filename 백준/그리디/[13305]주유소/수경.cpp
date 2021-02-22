#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {

	//입력
	int n; //도시 개수
	cin >> n;
	
	vector<long long> dist(n);
	for (int i = 0; i < n - 1; i++)
		cin >> dist[i];

	priority_queue<long long, vector<long long>, greater<long long>> cost; //최소힙
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		cost.push(x);
		ans += cost.top() * dist[i];
	}

	cout << ans;

	return 0;
}
