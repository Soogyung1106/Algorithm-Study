#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 100

using namespace std;

int n, l;
int map[MAX][MAX];

bool check_route(vector<int>& v)
{
	vector<bool> visited(n, false);

	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] != v[i]) 
		{
			int gap = abs(v[i] - v[i - 1]);

			if (gap != 1) return false;

			// 더 높을때
			if (v[i - 1] < v[i]) 
			{
				for (int j = 1; j <= l; j++) 
				{
					// 경사로 범위를 벗어나는 경우
					if (i - j < 0) return false;
					// 높이가 다른 경우
					if (v[i - 1] != v[i - j]) return false;
					// 이미 경사로가 있는 경우
					if (visited[i - j]) return false;

					visited[i - j] = true;
				}
			}
			// 더 낮을때
			else 
			{

				for (int j = 0; j < l; j++) 
				{
					if (i + j >= n) return false;
					if (v[i] != v[i + j]) return false;
					if (visited[i + j]) return false;

					visited[i + j] = true;
				}
			}
		}

	}
	return true;
}

void init()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
}

int main()
{
	init();
	cin >> n >> l;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int answer = 0;
	
	for (int i = 0; i < n; i++)
	{
		vector<int> row;

		for (int j = 0; j < n; j++)
		{
			row.push_back(map[i][j]);
		}

		if (check_route(row)) 
		{
			answer++;
		}
	}

	for (int j = 0; j < n; j++)
	{
		vector<int> column;

		for (int i = 0; i < n; i++)
		{
			column.push_back(map[i][j]);
		}

		if (check_route(column))
		{
			answer++;
		}
	}

	cout << answer << endl;

	return 0;
}
