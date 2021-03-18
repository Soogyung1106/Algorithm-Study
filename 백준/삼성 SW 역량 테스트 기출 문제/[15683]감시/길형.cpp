#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define INF 987654321
#define MAX 9
using namespace std;

typedef pair<int, int> PAIR;

int n, m, answer, count;
int map[MAX][MAX];
int temp[MAX][MAX];
int cctv_dir[MAX];

// left right down up
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };

vector<PAIR> cctv;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}


void copy() 
{
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			temp[i][j] = map[i][j];
}

void detect(int x, int y, int d) // 해당 좌표부터 원하는 방향까지 감시범위를 구하는 함수
{
	int nx = x;
	int ny = y;

	while (true) 
	{
		nx += dx[d];
		ny += dy[d];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;

		if (temp[nx][ny] == 0) // 빈칸 범위 확장
		{
			temp[nx][ny] = 7;
		}
		else if (temp[nx][ny] == 6) // 벽
		{
			break;
		}
	}
}

void set_cctv() // 모든 cctv를 설정한 방향대로 감시, 1~5에 따라 detect 함수를 다르게 사용함
{
	for (int i = 0; i < cctv.size(); i++) 
	{
		int x = cctv[i].first;
		int y = cctv[i].second;

		switch (temp[x][y]) 
		{
		case 1:
		{
			// left right down up 중 하나
			int dir = cctv_dir[i];
			detect(x, y, dir);
			break;
		}

		case 2:
		{
			if (cctv_dir[i] == 1) 
			{
				detect(x, y, 1);
				detect(x, y, 2);
			}
			else 
			{
				detect(x, y, 3);
				detect(x, y, 4);
			}

			break;
		}
		case 3:
		{
			if (cctv_dir[i] == 1) 
			{
				detect(x, y, 1);
				detect(x, y, 4);
			}
			else if (cctv_dir[i] == 2) 
			{
				detect(x, y, 1);
				detect(x, y, 3);
			}
			else if (cctv_dir[i] == 3) 
			{
				detect(x, y, 2);
				detect(x, y, 3);
			}
			else if (cctv_dir[i] == 4) 
			{
				detect(x, y, 2);
				detect(x, y, 4);
			}
			break;
		}
		case 4:
		{
			if (cctv_dir[i] == 1) 
			{
				detect(x, y, 1);
				detect(x, y, 2);
				detect(x, y, 4);
			}
			else if (cctv_dir[i] == 2) 
			{
				detect(x, y, 1);
				detect(x, y, 3);
				detect(x, y, 4);
			}
			else if (cctv_dir[i] == 3) 
			{
				detect(x, y, 1);
				detect(x, y, 2);
				detect(x, y, 3);
			}
			else if (cctv_dir[i] == 4) 
			{
				detect(x, y, 2);
				detect(x, y, 3);
				detect(x, y, 4);
			}
			break;
		}
		case 5:
		{
			detect(x, y, 1);
			detect(x, y, 2);
			detect(x, y, 3);
			detect(x, y, 4);
			break;
		}

		default:
			break;
		}
	}
}


int check() // 사각지대를 구하는 함수
{
	int space = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (temp[i][j] == 0) space++;
		}
	}
	return space;
}

void dfs(int idx, int cnt) 
{
	if (cnt == cctv.size()) // 모든 cctv의 방향을 설정했다면
	{
		copy(); // 임시 배열 복제
		set_cctv();
		answer = min(answer, check());
		return;
	}

	int x = cctv[idx].first;
	int y = cctv[idx].second;

	
	for (int k = 1; k <= 4; k++) // cctv 방향 설정
	{
		// 2번과 5번은 각각 2개, 1개의 방향만 존재하므로 예외 처리
		if (map[x][y] == 5 && k > 1) continue;
		if (map[x][y] == 2 && k > 2) continue;

		cctv_dir[idx] = k;
		dfs(idx + 1, cnt + 1);
		cctv_dir[idx] = 0;
	}
}

int main() 
{
	init();
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5)
			{
				cctv.push_back(PAIR(i, j));
			}
		}
	}

	answer = INF;
	dfs(0, 0);
	cout << answer << endl;

	return 0;
}
