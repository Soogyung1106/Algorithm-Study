#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#define endl "\n"
#define MAX 21
#define MAX_VALUE 401

using namespace std;

int N;
int now_y, now_x;
int eat, body = 2;
int min_dist, min_y, min_x, answer;
int map[MAX][MAX]; // 맵
int check[MAX][MAX]; // 이동거리

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { -1, 1, 0, 0 };

void init_check() 
{
	min_dist = MAX_VALUE;
	min_y = MAX;
	min_x = MAX;

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			check[i][j] = -1;
		}
	}
}

void bfs(int y, int x) 
{
	queue<pair<int, int>> q;
	
	check[y][x] = 0;
	q.push({ y, x });

	while (!q.empty()) 
	{
		pair<int, int> now = q.front();
		q.pop();

		int y = now.first;
		int x = now.second;

		for (int i = 0; i < 4; i++) 
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
			
			if (check[ny][nx] != -1 || map[ny][nx] > body) continue; // 이미 방문했거나, 상어의 크기보다 큰 물고리인 경우

			check[ny][nx] = check[y][x] + 1;

			
			if (map[ny][nx] != 0 && map[ny][nx] < body) // 먹을 수 있는 물고기일 경우
			{
				if (min_dist > check[ny][nx]) 
				{
					min_y = ny;
					min_x = nx;
					min_dist = check[ny][nx];
				}
				else if (min_dist == check[ny][nx]) // 현재 물고기 까지의 이동시간은 같으면
				{
					if (min_y == ny) 
					{
						if (min_x > nx) 
						{
							min_y = ny;
							min_x = nx;
						}
					}
					else if (min_y > ny) 
					{
						min_y = ny;
						min_x = nx;
					}
				}
			}

			q.push({ ny, nx });
		}
	}
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

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			cin >> map[i][j];

			if (map[i][j] == 9) 
			{
				now_y = i;
				now_x = j;

				map[i][j] = 0;
			}
		}
	}

	while (true) 
	{
		init_check();

		bfs(now_y, now_x);

		
		if (min_y != MAX && min_x != MAX) // 먹을 수 있는 물고기를 찾은 경우
		{
			answer += check[min_y][min_x];

			eat++;

			if (eat == body) 
			{
				body++;
				eat = 0;
			}

			map[min_y][min_x] = 0;

			now_y = min_y;
			now_x = min_x;
		}
		else 
		{
			break;
		}
	}

	cout << answer << endl;

	return 0;
}
