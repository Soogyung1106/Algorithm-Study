#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 52

using namespace std;

int T;
int N, M; // 맵크기, 거울 개수
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int map[MAX][MAX];

vector<pair<int, int>> answer;

void dfs(int y, int x, int dir) 
{
	if (y == 0 || x == 0 || y == N + 1 || x == N + 1) 
	{
		cout << y << " " << x << endl;

		return;
	}

	if (map[y][x] == 1) 
	{		
		int nd = (dir + 1) % 4;

		dfs(y + dy[nd], x + dx[nd], nd);
	}
	else dfs(y + dy[dir], x + dx[dir], dir);
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
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		cin >> N >> M;

		for (int i = 0; i < N + 2; i++)
		{
			for (int j = 0; j < N + 2; j++)
			{
				map[i][j] = 0;
			}
		}

		int y, x;

		for (int i = 0; i < M; i++) 
		{
			cin >> y >> x;

			map[y][x] = 1;
		}

		cin >> y >> x;

		if (y == 0) dfs(y + 1, x, 2); // 아래
		else if (y == N + 1) dfs(y - 1, x, 0); // 위
		else if (x == 0) dfs(y, x + 1, 1); // 우
		else if (x == N + 1) dfs(y, x - 1, 3); // 좌
	}

	
	

	return 0;
}
