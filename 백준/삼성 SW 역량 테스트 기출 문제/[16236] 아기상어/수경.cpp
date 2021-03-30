#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

int map[21][21];
int visited[21][21];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
int size = 2;
int n;
int sharkY;
int sharkX;
int ate;
int time;
bool ateFlag = false;

void createMap() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 9) {
				sharkY = i;
				sharkX = j;
				map[i][j] = 0;
			}
		}
	}
}

void bfs() {
	std::queue<std::pair<int, int>>q;
	std::vector<std::pair<int, int>>v;
	q.push({ sharkY, sharkX });
	visited[sharkY][sharkX] = 1;
	ateFlag = false;

	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= 0 && nx >= 0 && ny < n && nx < n && visited[ny][nx] == 0) {
					if (map[ny][nx] == 0 || map[ny][nx] == size) { // 상어가 이동 가능
						q.push({ ny, nx });
						visited[ny][nx] = visited[y][x] + 1;
					}
					else if (map[ny][nx] < size) { // 물고기를 만남
						v.push_back({ ny, nx });
						visited[ny][nx] = visited[y][x] + 1;
					}
				}
			}
		}
		if (v.size() >= 1) { // 먹을 수 있는 물고기가 여러마리일 때
			std::sort(v.begin(), v.end());
			map[v[0].first][v[0].second] = 0;
			ateFlag = true;
			sharkY = v[0].first;
			sharkX = v[0].second;
			ate++;
			time += visited[v[0].first][v[0].second] - 1;
			break;
		}
	}
}

int main() {
	createMap();
	while (1) {
		bfs();

		memset(visited, 0, sizeof(visited));
		if (ateFlag == false) break;
		else if (ate == size) {
			size++;
			ate = 0;
		}
	}
	std::cout << time;
}
