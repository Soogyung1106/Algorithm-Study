#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)

#define MAX 26

using namespace std;

vector<vector <int>> map(MAX, vector<int>(MAX, 0)); // 초기화 배열말고 벡터 써보기!
bool visit[MAX][MAX];
int mv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int n;

void bfs(int y, int x, int count)
{
	queue<pair<int, int>> temp; // pair(y, x) 순서

	visit[y][x] = true; // 방문했음
	map[y][x] = count;
	temp.push(make_pair(y, x));

	while (!temp.empty())
	{
		int y_now = temp.front().first;
		int x_now = temp.front().second;

		temp.pop();

		for (int i = 0; i < 4; i++)
		{
			int y_next = y_now + mv[i][1];
			int x_next = x_now + mv[i][0];

			if ((x_next >= 0 && x_next < n) && (y_next >= 0 && y_next < n))
			{
				if (!visit[y_next][x_next] && map[y_next][x_next] == 1)
				{
					visit[y_next][x_next] = true;
					map[y_next][x_next] = count;
					temp.push(make_pair(y_next, x_next));
				}
			}

		}
	}
}


int main()
{
	vector<int> group;
	int count = 0;

	freopen("input.txt", "r", stdin);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j] && map[i][j]) // 방문 X && map == 1
			{
				count++;
				bfs(i, j, count);
			}
		}
	}

	for (int k = 1; k <= count; k++)
	{
		int num = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == k) 
				{
					num++;
				}
			}
		}
		group.push_back(num);
	}

	sort(group.begin(), group.end());

	cout << count << endl;

	for (auto num : group)
	{
		cout << num << endl;
	}
	
	return 0;
}
