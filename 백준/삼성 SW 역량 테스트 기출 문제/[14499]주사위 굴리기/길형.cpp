#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <deque>
#define endl "\n"
#define MAX 21
using namespace std;

int map[MAX][MAX];
int state[6]; // 순서대로 [0]Top,[1]Bottom,[2]North,[3]South,[4]West,[5]East
int temp[6];
int N, M, K, X, Y;
pair<int, int> now; // x, y
deque<int> direction;
int dx[5] = { 0,1,-1,0,0 }; // 동,서,북,남
int dy[5] = { 0,0,0,-1,1 };

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void copy()
{
	for (int i = 0; i < 6; i++) temp[i] = state[i];
}

void north() // S -> T, T -> N, N -> B, B -> S
{
	copy();
	state[0] = temp[3];
	state[2] = temp[0];
	state[1] = temp[2];
	state[3] = temp[1];
}

void south() // S <- T, T <- N, N <- B, B <- S
{
	copy();
	state[0] = temp[2];
	state[3] = temp[0];
	state[1] = temp[3];
	state[2] = temp[1];
}

void east() // W -> T, T -> E, E -> B, B -> W 
{
	copy();
	state[0] = temp[4];
	state[5] = temp[0];
	state[1] = temp[5];
	state[4] = temp[1];
}

void west() // W <- T, T <- E, E <- B, B <- W 
{
	copy();
	state[4] = temp[0];
	state[0] = temp[5];
	state[5] = temp[1];
	state[1] = temp[4];
}

bool range(int x, int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N) return true;

	return false;
}

void process(int x, int y)
{
	if (map[y][x] == 0)
	{
		map[y][x] = state[1];
	}
	else
	{
		state[1] = map[y][x];
		map[y][x] = 0;
	}

	cout << state[0] << endl;
}

void sequence(int dir)
{
	if (range(now.first + dx[dir], now.second + dy[dir]))
	{
		return;
	}

	now.first += dx[dir];
	now.second += dy[dir];

	switch (dir)
	{
		case 1:
			east();
			break;
		case 2:
			west();
			break;
		case 3:
			north();
			break;
		case 4:
			south();
			break;
	}

	process(now.first, now.second);
}

int main(void)
{
	init();
	cin >> N >> M >> Y >> X >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	now = { X, Y };

	for (int i = 0; i < K; i++)
	{
		int dir;
		cin >> dir;
		sequence(dir);
	}

	return 0;
}
