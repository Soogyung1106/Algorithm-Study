#include <iostream>
using namespace std;

int main() {

	//입력 
	int T, N, M, a, b;
	cin >> T;
	while (T--) {
		cin >> N >> M; //정점, 간선 개수 
		while (M--) {
			cin >> a >> b;
		}

		cout << N - 1<<'\n';
	}

	return 0;
}
