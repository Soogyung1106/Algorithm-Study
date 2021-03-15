#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#define endl "\n"
#define MAX 8

using namespace std;

int n, m;
int safe_zone, bfs_zone, max_zone;
int map[MAX][MAX];
queue<pair<int, int>> q;
vector<pair<int, int> > virus;
pair<int,int> mv[4] = { {0,1}, {0,-1},{1,0},{-1,0} };

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void BFS(int x1, int y1, bool visited[MAX][MAX]) //바이러스의 위치(x1, y1)
{
	bfs_zone = 0;

	visited[y1][x1] = true;
	q.push(make_pair(x1, y1));

	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int nx = now.first + mv[i].first;
			int ny = now.second + mv[i].second;

			if (nx < m && nx >= 0 && ny < n && ny >= 0 && !visited[ny][nx] && map[ny][nx] == 0) 
			{
				q.push({nx,ny});
				visited[ny][nx] = true;
				bfs_zone++;
			}
		}
	}
}

void DFS(int cnt, int x, int y) // 벽을 cnt만큼 세우는 경우(경우의 수)
{
	if (cnt == 3) 
	{
		int area = safe_zone - 3;
		bool visited[MAX][MAX] = { 0, };

		for (int i = 0; i < virus.size(); i++) 
		{
			BFS(virus[i].first, virus[i].second, visited);
			area -= bfs_zone;
		}

		if (max_zone < area) max_zone = area;

		return;
	}

	if (x >= m) // 줄 바꾸기
	{
		x = 0;
		y++;
	}

	if (y >= n) return; // 탐색 종료

	if (map[y][x] == 0) 
	{
		map[y][x] = 1;
		DFS(cnt + 1, x + 1, y);
		map[y][x] = 0;
	}

	DFS(cnt, x + 1, y);
}

int main(void) 
{
	init();
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
		{
			cin >> map[i][j];
			if (map[i][j] == 0) safe_zone++;
			if (map[i][j] == 2) virus.push_back(make_pair(j, i));
		}

	DFS(0, 0, 0);
	cout << max_zone << endl;

	return 0;
}
