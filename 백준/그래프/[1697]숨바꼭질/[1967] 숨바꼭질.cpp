#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	//입력
	int from, to; //수빈 위치, 동새 위치
	cin >> from >> to;

	//최단 시간 탐색
	vector<bool> visited(100001, false);
	queue<pair<int, int>> q; //위치, 소요된 시간
	q.push({ from, 0 });
	visited[from] = true;

	while (!q.empty()) {
		pair<int, int> front = q.front();
		q.pop();

		if (front.first == to) {
			cout << front.second;
			break;
		}
		
		if (front.first * 2 <= to + 1 && !visited[front.first * 2]) {
			q.push({ front.first * 2, front.second + 1 });
			visited[front.first * 2] = true;
		}if (front.first + 1 <= to && !visited[front.first + 1]) {
			q.push({ front.first + 1, front.second + 1 });
			visited[front.first + 1] = true;
		}if (0 <= front.first - 1 && !visited[front.first - 1]) {
			q.push({ front.first - 1, front.second + 1 });
			visited[front.first - 1] = true;
		}

	}

	return 0;
}