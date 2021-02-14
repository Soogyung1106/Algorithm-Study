/* 참고
https://hyunjae-lee.github.io/hyunjae-lee.github.io/boj/dfs/bfs/2206sol/
*/
#include <cstdio>
#include <queue>
#include <tuple>
#define MAX 1001
using namespace std;

int map[MAX][MAX];
int dist[MAX][MAX][2];

const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0,0, -1, 1 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	queue< tuple<int, int, int>> q;
	dist[0][0][0] = 1;
	q.push(make_tuple(0, 0, 0));

	while (!q.empty()) {
		int y, x, z;
		tie(y, x, z) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nextY = y + dy[dir];
			int nextX = x + dx[dir];

			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
				// 다음 노드가 벽이 아니고 방문한 적이 없으면,
				if (map[nextY][nextX] == 0 && dist[nextY][nextX][z] == 0) {
					dist[nextY][nextX][z] = dist[y][x][z] + 1;
					q.push(make_tuple(nextY, nextX, z));
				}

				// 벽을 부순 횟수가 0이고, 다음 노드가 벽이고 방문한 적이 없으면,
				else if (z == 0 && map[nextY][nextX] == 1 && dist[nextY][nextX][1] == 0) {
					dist[nextY][nextX][1] = dist[y][x][0] + 1;
					q.push(make_tuple(nextY, nextX, 1));
				}
			}
		}
	}

	int MIN = -1;
	if (dist[n - 1][m - 1][0] != 0 && dist[n - 1][m - 1][1] != 0) {
		MIN = min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
	}
	else if (dist[n - 1][m - 1][0] != 0) {
		MIN = dist[n - 1][m - 1][0];
	}
	else if (dist[n - 1][m - 1][1] != 0) {
		MIN = dist[n - 1][m - 1][1];
	}

	printf("%d\n", MIN);

	return 0;
}