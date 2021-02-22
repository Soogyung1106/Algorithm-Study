#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	//입력
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	//오름차순 정렬
	sort(v.begin(), v.end()); 

	//시간의 합 최솟값
	int sum = 0; int k = n;
	for (int i = 0; i < n; i++) {
		sum += v[i] * k;
		k--;
	}

	cout << sum;

	return 0;
}