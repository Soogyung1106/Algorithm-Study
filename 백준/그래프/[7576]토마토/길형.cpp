#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int box[1001][1001];
int check[1001][1001];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;

int Max()
{
	int maxnum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 0)
				return -1;
			else if (check[i][j] > maxnum)
				maxnum = check[i][j];
		}
	}

	return maxnum - 1;
}

int main()
{
	int x, y;
	queue<pair<int, int>> q;
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &box[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 1 && check[i][j] == 0)
			{

				q.push(make_pair(i, j));
				check[i][j] = 1;
			}
		}
	}

	while (!q.empty()) //BFS
	{
		x = q.front().first;
		y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x_now = x + dx[i];
			int y_now = y + dy[i];

			if (0 <= x_now && x_now < N && 0 <= y_now && y_now < M)
			{
				if (box[x_now][y_now] == 0 & check[x_now][y_now] == 0) //토마토가 익지 않았으면 익힌다
				{
					check[x_now][y_now] = check[x][y] + 1;
					q.push(make_pair(x_now, y_now));
					box[x_now][y_now] = 1;
				}
				else if (box[x_now][y_now] == -1 && check[x_now][y_now] == 0)
				{
					check[x_now][y_now] = -1;
				}
			}
		}

	}

	printf("%d", Max());

	return 0;
}
