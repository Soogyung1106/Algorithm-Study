#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int n, m; // 입력 받은 행, 열
int maze[MAX][MAX]; // 맵
bool visit[MAX][MAX];
int mv[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} }; // y, x 값 이동

int bfs(int y, int x)
{
	queue<pair<int, int>> temp; // pair(y, x) 순서

	visit[y][x] = true; // 방문했음
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

			if ((x_next >= 0 && x_next < m) && (y_next >= 0 && y_next < n))
			{
				if (!visit[y_next][x_next] && maze[y_next][x_next] == 1)
				{
					visit[y_next][x_next] = true;
					maze[y_next][x_next] = maze[y_now][x_now] + 1; // maze 값에 움직인 수를 count해서 계속 누적해줌.
					temp.push(make_pair(y_next, x_next));
				}
			}
		}
	}

	return maze[n - 1][m - 1];
}


int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			scanf("%1d", &maze[i][j]); // 맨 처음 cin으로 받았더니 getline()처럼 받아져서 계속 틀림...ㅠ
		}
	}

	int answer = bfs(0, 0);

	cout << answer << endl;

	return 0;
}
