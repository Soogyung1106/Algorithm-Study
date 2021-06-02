#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#include <cstring>
#define endl "\n"
#define MAX 101

using namespace std;

int N, M, R;
int score;
int map[MAX][MAX];
int state[MAX][MAX];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0,  0};

int chage_d(char d)
{
	if (d == 'E') return 0;
	else if (d == 'W') return 1;
	else if (d == 'S') return 2;
	else return 3;
}

void attack_turn(int Y, int X, int d)
{
	queue<pair<int, int>> q;
	q.push({ Y,X });

	if (state[Y][X] == false) return;
	else
	{
		state[Y][X] = false;
		score++;
	}
	
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		int hight = map[y][x];

		q.pop();

		for (int i = 1; i < hight; i++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 1 || ny > N || nx < 1 || nx > M) continue;
			if (state[ny][nx] == false)
			{
				y = ny;
				x = nx;
				continue;
			}
			else
			{
				y = ny;
				x = nx;
				state[ny][nx] = false;
				score++;
				q.push({ y,x });
			}			
		}
	}
}

void print_state(void)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (state[i][j])
			{
				cout << "S";
			}
			else
			{
				cout << "F";
			}

			if (j != M) cout << " ";
		}

		cout << endl;
	}
}

void defense_turn(int Y, int X)
{
	state[Y][X] = true;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> N >> M >> R;

	memset(state, true, sizeof(state));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	R *= 2;

	for (int i = 0; i < R; i++)
	{
		int Y, X;
		char D;

		if (i % 2 == 0) // 공격
		{
			cin >> Y >> X >> D;

			int d = chage_d(D);

			attack_turn(Y, X, d);
		}
		else // 수비
		{
			cin >> Y >> X;

			defense_turn(Y, X);
		}
	 }

	cout << score << endl;
	print_state();

	return 0;
}
