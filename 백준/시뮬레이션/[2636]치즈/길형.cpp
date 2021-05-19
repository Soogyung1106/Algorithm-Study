#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define endl "\n"
#define MAX 100

using namespace std;

struct cheese {
	int x, y;
};

int n, m, answer, piece;
int board[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void bfs() 
{
	memset(check, false, sizeof(check));
	queue<cheese> q;

	q.push({ 0, 0 });
	check[0][0] = true;

	while (!q.empty()) 
	{
		int x = q.front().x;
		int y = q.front().y;
		
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (check[nx][ny]) continue;

			if (board[nx][ny] >= 1) 
			{
				board[nx][ny] += 1;
				continue;
			}

			q.push({ nx, ny });
			check[nx][ny] = true;
		}
	}
}

bool melt() 
{
	bool melted = false;
	int cnt = 0;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (board[i][j] >= 2) 
			{
				board[i][j] = 0;
				melted = true;
				cnt += 1;
			}
		}
	}
	if (cnt) piece = cnt;

	return melted;
}

int main() 
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			cin >> board[i][j];
		}
	}

	while (true) 
	{
		bfs();
		if (melt()) answer++;
		else break;
	}

	cout << answer << endl << piece << endl;

	return 0;
}
