#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#define endl "\n"
#define MAX 50

using namespace std;

int map[MAX][MAX];
int R, C, T;
int upX, upY, downX, downY; // 공기 청정기 좌표
int rc[4] = { 2,0,3,1 }; // 반시계
int c[4] = { 2,1,3,0 }; // 시계 방향
pair<int, int> mv[4] = { {-1,0},{1,0},{0,1},{0,-1} };

void Copy(int temp_map[50][50])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			temp_map[i][j] = map[i][j];
		}
	}
}

int CleanAir()
{
	for (int t = 0; t < T; t++)
	{
		int temp_map[50][50];

		Copy(temp_map);
		queue<pair<int, int>> q;

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] != 0 && map[i][j] != -1)
				{
					q.push(make_pair(i, j));
				}
			}
		}

		while (!q.empty()) // 먼지 확산
		{
			int y = q.front().first;
			int x = q.front().second;
			int dust = temp_map[y][x] / 5;

			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + mv[i].first;
				int nx = x + mv[i].second;

				if ((0 <= ny && ny < R) && (0 <= nx && nx < C) && temp_map[ny][nx] != -1)
				{
					map[ny][nx] += dust;
					map[y][x] -= dust;
				}
			}
		}

		Copy(temp_map);

		int y = upY;
		int x = upX + 1;
		map[y][x] = 0;

		for (int i = 0; i < 4; i++) // 반시계
		{
			while (1)
			{
				// →, ↑, ←, ↓
				int ny = y + mv[rc[i]].first;
				int nx = x + mv[rc[i]].second;

				if (ny == upY && nx == upX) break; // 공기청정기
				if (ny < 0 || ny >= R || nx < 0 || nx >= C) break; // 방향 전환 구역

				map[ny][nx] = temp_map[y][x];
				y = ny;
				x = nx;
			}
		}

		y = downY;
		x = downX + 1;
		map[y][x] = 0;

		for (int i = 0; i < 4; i++) // 시계
		{
			while (1)
			{
				// →, ↓, ←, ↑
				int ny = y + mv[c[i]].first;
				int nx = x + mv[c[i]].second;

				if (ny == downY && nx == downX) break; // 공기청정기
				if (ny < 0 || ny >= R || nx < 0 || nx >= C) break; // 방향 전환 구역

				map[ny][nx] = temp_map[y][x];
				y = ny;
				x = nx;
			}
		}
	}

	int result = 0;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] >= 1) result += map[i][j];
		}
	}

	return result;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	void init();
	cin >> R >> C >> T;
	bool flag = false;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == -1)
			{
				if (!flag) // 첫 -1
				{
					upY = i;
					upX = j;

					flag = true;
				}
				else // 둘 -1
				{
					downY = i;
					downX = j;
				}
			}
		}
	}
	cout << CleanAir() << endl;

	return 0;
}
