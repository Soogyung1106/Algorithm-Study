#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 22
#define INF 987654321
using namespace std;

bool check[MAX];
int map[MAX][MAX];
int N, gap = INF;

void dfs(int count, int index)
{
	if (count == N / 2) // 종료조건
	{
		int start = 0;
		int link = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (check[i] && check[j]) start += map[i][j]; // true -> start 팀
				if (!check[i] && !check[j]) link += map[i][j]; // false -> link 팀
			}
		}

		if (abs(start - link) < gap) gap = abs(start - link);

		return;
	}

	for (int i = index; i < N; i++)
	{
		check[i] = true;
		dfs(count + 1, i + 1);
		check[i] = false;
	}
}

int main(void)  
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	dfs(0, 1);

	cout << gap << endl;

	return 0;
}
