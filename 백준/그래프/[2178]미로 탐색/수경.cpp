#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<vector<int>> maze;
vector<vector<int>> visited;

void bfs(int i, int j) {
	
	queue<pair<int, int>> pq;
	pq.push(make_pair(i, j));
	visited[i][j] = 1; //방문 체크
	
	vector<pair<int, int>> moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	while (!pq.empty()) {
		pair<int, int> front = pq.front();
		pq.pop();

		for (auto move : moves) {
			pair<int, int> next = { front.first + move.first, front.second + move.second };

			//범위를 벗어나지 않고.
			if (0 <= next.first && next.first < maze.size() && 0 <= next.second && next.second < maze[0].size()) {
				//갈 수 있는 길(=1) 이고 방문한 적 없다면(=0)
				if (maze[next.first][next.second] && !visited[next.first][next.second]) {
					visited[next.first][next.second] = visited[front.first][front.second]+1;
					pq.push(next);
				}
			}
		}
	}

}

int main() {

	//입력 
	int n, m;
	cin >> n >> m;
	maze.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &maze[i][j]);
		}
	}

	//탐색
	visited.resize(n, vector<int>(m, 0));
	bfs(0, 0); //(1,1) 부터 탐색 시작

	//출력 
	cout << visited[n - 1][m - 1];

	return 0;
}