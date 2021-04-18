#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#define endl "\n"
#define MAX 11

using namespace std;

int n, m;
char map[MAX][MAX];
bool visit[MAX][MAX][MAX][MAX] = { 0, };
int answer;

int ry, rx, by, bx;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int bfs() 
{
	queue <pair<int, int>> red_que;
	queue <pair<int, int>> blue_que;

	red_que.push({ ry, rx });
	blue_que.push({ by, bx });
	visit[ry][rx][by][bx] = 1;


	while (!red_que.empty())
	{
		int sized = red_que.size();

		while (sized--) 
		{
			int red_y = red_que.front().first;
			int red_x = red_que.front().second;
			int blue_y = blue_que.front().first;
			int blue_x = blue_que.front().second;

			red_que.pop();
			blue_que.pop();

			if (map[red_y][red_x] == 'O') return answer;

			for (int i = 0; i < 4; i++) 
			{
				int red_ny = red_y;
				int red_nx = red_x;
				int blue_ny = blue_y;
				int blue_nx = blue_x;

				while (map[red_ny + dy[i]][red_nx + dx[i]] != '#' && map[red_ny][red_nx] != 'O') 
				{
					red_ny += dy[i];
					red_nx += dx[i];
				}

				while (map[blue_ny + dy[i]][blue_nx + dx[i]] != '#' && map[blue_ny][blue_nx] != 'O') 
				{
					blue_ny += dy[i];
					blue_nx += dx[i];
				}

				if (red_ny == blue_ny && red_nx == blue_nx) 
				{

					if (map[red_ny][red_nx] == 'O') continue;

					if ((abs(red_ny - red_y) + abs(red_nx - red_x)) > (abs(blue_ny - blue_y) + abs(blue_nx - blue_x))) // 빨간공이 움직이는 방향 더 앞이면, 빨간색 공이 이동
					{
						red_ny -= dy[i];
						red_nx -= dx[i];
					}
					else // 파란공이 움직이는 방향 더 앞이면, 파란공이
					{
						blue_ny -= dy[i];
						blue_nx -= dx[i];
					}
				}

				if (visit[red_ny][red_nx][blue_ny][blue_nx]) continue;

				red_que.push({ red_ny, red_nx });
				blue_que.push({ blue_ny, blue_nx });
				visit[red_ny][red_nx][blue_ny][blue_nx] = 1;
			}

		}

		if (answer == 10) return -1;

		answer++;
	}

	return -1;
}

void init(void)
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
}

int main() 
{
	init();
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				ry = i;
				rx = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B')
			{
				by = i;
				bx = j;
				map[i][j] = '.';
			}
		}
	}
		
	cout << bfs() << endl;

	return 0;
}
