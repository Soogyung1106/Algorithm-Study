#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 51

using namespace std;

int n, m;
int map[MAX][MAX];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int answer;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void dfs(int x, int y, int direction) 
{
	if (map[x][y] == 0) // 아직 청소 안됨
	{
		map[x][y] = 2; // 청소 마킹
		answer++;
	}

	for (int i = 0; i < 4; i++) 
	{
		int nd = (direction + 3 - i) % 4;
		int nx = x + dx[nd];
		int ny = y + dy[nd];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) // 범위 체크
		{
			continue;
		}

		if (map[nx][ny] == 0) 
		{
			dfs(nx, ny, nd);
		}
	}

	int nd = (direction + 2) % 4;
	int nx = x + dx[nd];
	int ny = y + dy[nd];

	if (map[nx][ny] == 1) 
	{
		cout << answer;
		exit(0);
	}
	dfs(nx, ny, direction); // 바라보는 방향 direction은 유지
}


int main(void) 
{
	init();
	cin >> n >> m;

	int r, c, direction;
	cin >> r >> c >> direction;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			cin >> map[i][j];
		}
	}

	dfs(r, c, direction);

	return 0;
}
