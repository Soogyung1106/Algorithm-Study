#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <queue>
#define endl "\n"
#define MAX 21

using namespace std;

typedef struct TAXI {
	int y, x, fuel;
} TAXI;

typedef struct CUSTOMER {
	int start_y, start_x;
	int end_y, end_x;
} CUSTOMER;

int n, m;
int map[MAX][MAX];
int visit[MAX][MAX];
int flag;
int start_end;
int dist = 987654321;
TAXI taxi;
vector<CUSTOMER> person;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int bfs(int Y, int X)
{
	memset(visit, 0, sizeof(visit));
	
	if (taxi.y == Y && taxi.x == X) // 택시, 사람 같은 위치인 경우
	{
		return 0;
	}

	queue<pair<int, int>> q;

	visit[taxi.y][taxi.x] = 1;
	q.push({ taxi.y,taxi.x });

	int result = 0;

	while (!q.empty())
	{
		int q_size = q.size();

		for (int i = 0; i < q_size; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];

				if ((0 >= ny || ny > n) || (0 >= nx || nx > n)) continue; // 범위
				if (visit[ny][nx] == 1) continue; // 방문기록
				if (map[ny][nx] == 1) continue; // 벽

				if (ny == Y && nx == X) return result + 1;

				visit[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
		result++;
	}

	return -1;
}

void find_route()
{
	for (int i = 0; i < person.size(); i++)
	{
		int sum = bfs(person[i].start_y, person[i].start_x);
		
		if (sum == -1) // 갈 수 없는 경우
		{
			flag = 1;
			return;
		}
		else if (dist > sum)
		{
			dist = sum;
			start_end = i;
		}
		else if (dist == sum)
		{
			if (person[start_end].start_y > person[i].start_y)
			{
				start_end = i;
			}
			else if (person[start_end].start_y == person[i].start_y)
			{
				if (person[start_end].start_x > person[i].start_x)
				{
					start_end = i;
				}
			}
		}
	}
}

int main(void)
{
	init();
	cin >> n >> m >> taxi.fuel;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	cin >> taxi.y >> taxi.x;

	for (int i = 0; i < m; i++)
	{
		CUSTOMER temp;
		cin >> temp.start_y >> temp.start_x >> temp.end_y >> temp.end_x;
		person.push_back(temp);
	}

	while (true)
	{
		dist = 987654321;
		find_route(); // dist : 현재 택시 위치와 손님의 거리, start_end : 시작점, 도착지점

		if (flag == -1) // 갈 수 없는 곳이 있다면
		{
			cout << -1 << endl;
			return 0;
		}

		if (taxi.fuel < start_end) //연료가 부족한 경우
		{
			cout << -1 << endl;
			return 0;
		}

		taxi.fuel -= dist;
		taxi.y = person[start_end].start_y;
		taxi.x = person[start_end].start_x;

		dist = 987654321;
		dist = bfs(person[start_end].end_y, person[start_end].end_x);

		if (dist == -1) // 목적지까지 경로가 없는 경우
		{
			cout << -1 << endl;
			return 0;
		}

		if (dist > taxi.fuel) // 목적지까지 연료가 부족한 경우
		{
			cout << -1 << endl;
			return 0;
		}

		taxi.fuel -= dist;
		taxi.y = person[start_end].end_y;
		taxi.x = person[start_end].end_x;
		person.erase(person.begin() + start_end);

		taxi.fuel += dist * 2; // 연료 채우기
		if (person.empty()) break; // 손님이 더 이상 없다면
	}
	cout << taxi.fuel << endl;

	return 0;
}
