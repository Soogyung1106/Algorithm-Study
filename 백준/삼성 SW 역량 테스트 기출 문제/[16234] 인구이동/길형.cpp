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
#define MAX 50

using namespace std;

int N, L, R;
int people, number;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<pair<int, int>> v;

pair<int, int> mv[4] = { {1,0},{-1,0},{0,1},{0,-1} }; // y,x

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + mv[i].first;
		int nx = x + mv[i].second;

		if ((0 <= ny && ny < N) && (0 <= nx && nx < N))
		{
			int gap = abs(map[y][x] - map[ny][nx]);

			if ((L <= gap && gap <= R) && !visit[ny][nx])
			{
				visit[ny][nx] = true; // 방문
				v.push_back({ ny,nx });
				people += map[ny][nx];
				number++;
				dfs(ny, nx);
			}
		}

	}
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
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	int result = 0;

	while (true)
	{
		memset(visit, false, sizeof(visit));

		bool check = false;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j]) continue;

				visit[i][j] = true;
				people = map[i][j];
				number = 1;

				v.clear();
				v.push_back({ i,j });
				dfs(i, j);

				if (number >= 2)
				{
					check = true;

					for (int k = 0; k < v.size(); k++)
					{
						map[v[k].first][v[k].second] = people / number;
					}
				}
			}
		}

		if (check) result++;
		else break;
	}
	cout << result << endl;

	return 0;
}
