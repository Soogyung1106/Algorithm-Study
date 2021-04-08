#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 500

using namespace std;

int	N, answer;
int MAP[MAX][MAX];
bool visit[MAX][MAX];
int spread[4][5][5] =
{
	{{0, 0, 2, 0, 0},
	 {0, 10, 7, 1, 0},
	 {5, -1, 0, 0, 0},
	 {0, 10, 7, 1, 0},
	 {0, 0, 2, 0, 0}},
	{{0, 0, 0, 0, 0},
	 {0, 1, 0, 1, 0},
	 {2, 7, 0, 7, 2},
	 {0, 10, -1, 10, 0},
	 {0, 0, 5, 0, 0}},
	{{0, 0, 2, 0, 0},
	 {0, 1, 7, 10, 0},
	 {0, 0, 0, -1, 5},
	 {0, 1, 7, 10, 0},
	 {0, 0, 2, 0, 0}},
	{{0, 0, 5, 0, 0},
	 {0, 10, -1, 10, 0},
	 {2, 7, 0, 7, 2},
	 {0, 1, 0, 1, 0},
	 {0, 0, 0, 0, 0}}
};

int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };

bool check(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= N) return false;

	return true;
}

void move(int y, int x, int dir)
{
	int target = MAP[y][x];
	int over = 0, moving = 0, ty = -1, tx = -1;

	visit[y][x] = true;
	MAP[y][x] = 0;

	for (int i = y - 2, a = 0; i < y + 3; i++, a++)
	{
		for (int j = x - 2, b = 0; j < x + 3; j++, b++)
		{
			if (check(i, j)) // 범위 내부
			{
				if (spread[dir][a][b] == -1)
				{
					ty = i, tx = j;
				}
				else
				{
					MAP[i][j] += target * spread[dir][a][b] / 100;
				}
			}
			else // 범위 밖으로 날아가는 것
			{
				if (spread[dir][a][b] != -1)
				{
					over += target * spread[dir][a][b] / 100;
				}
			}

			if (spread[dir][a][b] != -1) // alpha 연산을 위해 이동한 모래 계산
			{
				moving += target * spread[dir][a][b] / 100;
			}
		}
	}

	if (ty == -1)
	{
		over += target - moving;
	}
	else
	{
		MAP[ty][tx] += target - moving;
	}

	answer += over;
}

int rotate(int y, int x, int dir)
{
	int nd = (dir + 1) % 4; //왼쪽으로 회전 가능한 경우
	int ny = y + dy[nd];
	int nx = x + dx[nd];

	if (!visit[ny][nx]) return nd;

	ny = y + dy[dir]; // 범위 벗어난 경우
	nx = x + dx[dir];

	if (ny < 0 || nx < 0 || ny >= N || nx >= N) return nd;
	else return dir;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	int cnt = 0, dir = 0;
	int  y = N / 2, x = N / 2;

	visit[y + 1][x] = true;
	visit[y][x] = true;

	while (1)
	{
		cnt++;
		dir = rotate(y, x, dir);

		if (cnt == 1) visit[y + 1][x] = false;

		y = y + dy[dir];
		x = x + dx[dir];

		move(y, x, dir);

		if (y == 0 && x == 0) break;
	}

	cout << answer << endl;

	return 0;
}
