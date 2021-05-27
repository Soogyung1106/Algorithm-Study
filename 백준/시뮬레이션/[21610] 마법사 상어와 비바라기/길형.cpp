#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#define endl "\n"
#define MAX 50

using namespace std;

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[] = { 0,  0, -1, -1, -1, 0, 1, 1,  1 };
int dx[] = { 0, -1, -1,  0,  1, 1, 1, 0, -1 };

vector<pair<int, int>> cloud; // {y, x}

void InitCloud()
{
	cloud.push_back({ N - 1, 0 });
	cloud.push_back({ N - 1, 1 });
	cloud.push_back({ N - 2, 0 });
	cloud.push_back({ N - 2, 1 });
}

int ChangeLocation(int location)
{
	if (location == N) return 0;
	else if (location == -1) return N - 1;

	return location;
}

void MoveCloud(int d, int s)
{
	vector<pair<int, int>> temp = cloud;
	cloud.clear();

	for (int i = 0; i < temp.size() ; i++)
	{
		int y = temp[i].first;
		int x = temp[i].second;

		for (int j = 0; j < s; j++)
		{
			y = y + dy[d];
			x = x + dx[d];

			y = ChangeLocation(y);
			x = ChangeLocation(x);
		}

		map[y][x]++;
		cloud.push_back({ y,x });
		visit[y][x] = true;
	}
}

void CreateCloud()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] || map[i][j] < 2) continue;

			cloud.push_back({ i,j });
			map[i][j] -= 2;
		}
	}
}

void CopyWarter()
{
	for (int i = 0; i < cloud.size(); i++)
	{
		int y = cloud[i].first;
		int x = cloud[i].second;
		int water = 0;

		for (int j = 2; j <= 8; j+=2)
		{
			int ny = y + dy[j];
			int nx = x + dx[j];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

			if (map[ny][nx]) water++;
		}

		map[y][x] += water;
	}

	cloud.clear();
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
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	InitCloud();

	for (int i = 0; i < M; i++)
	{
		int d, s;
		cin >> d >> s;

		MoveCloud(d, s);
		CopyWarter();
		CreateCloud();

		memset(visit, false, sizeof(visit));
	}

	int answer = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			answer += map[i][j];
		
	cout << answer << endl;

	return 0;
}
