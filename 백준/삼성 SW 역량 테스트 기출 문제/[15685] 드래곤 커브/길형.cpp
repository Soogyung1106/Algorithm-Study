#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 101

using namespace std;

int N;
int x, y, d, g;
int next_y, next_x;
int answer;
int map[MAX][MAX];
pair<int, int> mv[4] = { {0,1},{-1,0},{0,-1},{1,0} };
vector<int> directions;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void dragon()
{
	int v_size = directions.size();
	for (int i = v_size - 1; i >= 0; i--)
	{
		int next_direction = (directions[i] + 1) % 4;
		y += mv[next_direction].first;
		x += mv[next_direction].second;
		map[y][x] = 1;
		directions.push_back(next_direction);
	}
}

int main(void)
{
	init();
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> d >> g;

		directions.clear();

		// 0세대 초기화
		map[y][x] = 1;
		y += mv[d].first;
		x += mv[d].second;
		map[y][x] = 1;

		directions.push_back(d);
		// g세대
		for (int j = 0; j < g; j++)
		{
			dragon();
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
				answer++;
		}
	}
	cout << answer << endl;

	return 0;
}

/*
0 == → , 1 == ↑ , 2 == ← , 3 == ↓

0세대 : 0

1세대 : 0 / 1

2세대 : 0 1 / 2 1

3세대 : 0 1 2 1 / 2 3 2 1

n세대 : (n-1)세대 + (n-1)세대의 역순 + 1
*/
