#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#define endl "\n"
#define MAX 52
using namespace std;

typedef struct INFO {
	int y;
	int x;
	int mass;
	int speed;
	int direction;
} INFO;

int N, M, K;
vector<INFO> map[MAX][MAX];
vector<INFO> fire;
pair<int, int> mv[8] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} }; // y,x
pair<int, int> odd_even[4] = { {0,1},{2,3},{4,5},{6,7} }; // first 동일 경우, second 동일하지 않은 경우

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void skill() // 파이어볼 이동
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			map[i][j].clear();
		}
	}

	for (int i = 0; i < fire.size(); i++)
	{
		int y = fire[i].y;
		int x = fire[i].x;

		int ny = y + mv[fire[i].direction].first * (fire[i].speed % N);
		int nx = x + mv[fire[i].direction].second * (fire[i].speed % N);

		if (ny > N) ny -= N;
		if (nx > N) nx -= N;
		if (ny < 1) ny += N;
		if (nx < 1) nx += N;

		map[ny][nx].push_back({ ny, nx, fire[i].mass, fire[i].speed, fire[i].direction });
		fire[i].y = ny;
		fire[i].x = nx;
	}
}

void merge_fire() // 파이어볼 합치기
{
	vector<INFO> temp;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j].empty()) continue;

			if (map[i][j].size() == 1) // 하나만 있으면 합치기 안해도 됨.
			{
				temp.push_back(map[i][j].front());
				continue;
			}

			int mass_total = 0;
			int speed_total = 0;

			bool even = true;
			bool odd = true;

			for (int index = 0; index < map[i][j].size(); index++) // 모두 홀,짝 판별
			{
				mass_total += map[i][j][index].mass;
				speed_total += map[i][j][index].speed;

				if (map[i][j][index].direction % 2 == 0) odd = false;
				else even = false;
			}

			int mass = mass_total / 5; // 분배
			int speed = speed_total / map[i][j].size(); // 분배

			if (mass == 0) continue; // 질량 == 0 이면 소멸

			if (even || odd) // 모두 홀 or 짝
			{
				for (int k = 0; k < 4; k++) temp.push_back({ i, j, mass, speed, odd_even[k].first });
			}
			else // 모두 홀 or 짝 아닌 경우
			{
				for (int k = 0; k < 4; k++) temp.push_back({ i, j, mass, speed, odd_even[k].second });
			}
		}
	}

	fire = temp;
}

int main(void)
{
	init();
	cin >> N >> M >> K;
	int sum = 0;

	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fire.push_back({ r, c, m, s, d });
		map[r][c].push_back({ r, c, m, s, d });
	}

	for (int i = 0; i < K; i++)
	{
		skill();
		merge_fire();
	}

	for (int i = 0; i < fire.size(); i++)
	{
		sum += fire[i].mass;
	}

	cout << sum << endl;

	return 0;
}
