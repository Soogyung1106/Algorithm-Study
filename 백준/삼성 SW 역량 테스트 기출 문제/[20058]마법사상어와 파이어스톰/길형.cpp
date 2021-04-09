#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#define endl "\n"
#define MAX 64

using namespace std;

int N, Q;
int map[MAX][MAX];
int temp[MAX][MAX];
bool state[MAX][MAX];
bool visit[MAX][MAX];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool check(int y, int x)
{
	if ((0 <= y && y < N) && (0 <= x && x < N))
	{
		return true;
	}
	return false; 
}

int dfs(int y, int x)
{
	visit[y][x] = true;
	int ice = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (check(ny, nx) && !visit[ny][nx] && map[ny][nx] > 0)
		{
			ice += dfs(ny, nx);
		}
	}

	return ice;
}

// 격자 시계방향 회전
void rotate(int y, int x, int L) 
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			temp[i][j] = map[y + L - 1 - j][x + i];
		}
	}
		
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			map[y + i][x + j] = temp[i][j];
		}
	}
}

void firestorm(int L) 
{
	L = pow(2,L);

	// 모든 격자에 대한 회전
	for (int i = 0; i < N; i += L)
	{
		for (int j = 0; j < N; j += L)
		{
			rotate(i, j, L);
		}
	}

	// 얼음 융해
	memset(state, false, sizeof(state));

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0) continue;
			int cnt = 0;

			for (int k = 0; k < 4; k++) 
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (!check(ny, nx)) continue;
				if (map[ny][nx] > 0) cnt++;
			}

			if (cnt < 3) state[i][j] = true;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (state[i][j]) map[i][j]--;
		}	
	}
}

// 가장 큰 덩어리 찾기 - DFS
int iceBest() 
{
	int ice_size = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] > 0 && !visit[i][j])
			{
				ice_size = max(ice_size, dfs(i, j));
			}
		}
	}
		
	return ice_size;
}

// 얼음 합 반환
int iceSum() 
{
	int ice = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ice += map[i][j];
		}
	}
		
	return ice;
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
	cin >> N >> Q;

	N = pow(2, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < Q; i++)
	{
		int L;
		cin >> L;
		firestorm(L);
	}

	cout << iceSum() << endl;
	cout << iceBest() << endl;

	return 0;
}
