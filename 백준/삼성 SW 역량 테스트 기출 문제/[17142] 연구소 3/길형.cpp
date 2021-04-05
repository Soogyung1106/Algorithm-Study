#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#define INF 987654321
#define MAX 51
#define endl "\n"

using namespace std;

int N, M, zero_count;
int answer = INF;
int map[MAX][MAX], time[MAX][MAX];
int check[10];
vector<pair<int, int>> virus;
queue<pair<int, int>>q;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs()
{
	int infect = 0;
	int total_time = 0;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if ((0 <= ny && ny < N) && (0 <= nx && nx < N)) // 범위체크
			{
				if (map[ny][nx] != 1 && time[ny][nx] == -1) // 벽이 아니고, 방문 안한 경우
				{
					time[ny][nx] = time[y][x] + 1; // 시간 증가
					
					if (map[ny][nx] == 0) // 바이러스가 아직 안퍼진 공간이면
					{
						infect++;
						total_time = time[ny][nx];
					}

					q.push({ ny,nx });
				}
			}
		}
		q.pop();
	}

	if (infect == zero_count) // 모든 빈칸에 바이러스가 퍼진 경우
	{
		answer = min(answer, total_time);
	}
}

void combination(int index, int count)
{
	if (count == M) // M개 만큼 선택 된 경우
	{
		memset(time, -1, sizeof(time)); // time배열 -1 로 초기화

		for (int i = 0; i < virus.size(); i++)
		{
			if (check[i])
			{
				q.push({ virus[i].first, virus[i].second });
				time[virus[i].first][virus[i].second] = 0;
			}
		}

		bfs();

		return;
	}

	for (int i = index; i < virus.size(); i++) // 바이러스 경우의 수
	{
		if (check[i]) continue;

		check[i] = 1;
		combination(i + 1, count + 1);
		check[i] = 0;
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
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 0) zero_count++;
			else if (map[i][j] == 2) virus.push_back({ i,j });
		}
	}

	combination(0, 0);
	
	if (answer == INF) cout << -1 << endl;
	else cout << answer << endl;

	return 0;
}
