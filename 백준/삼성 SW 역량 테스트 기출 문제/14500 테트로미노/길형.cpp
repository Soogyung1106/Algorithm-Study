#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define MAX 501
#define endl "\n"
using namespace std;

typedef pair<int, int> PAIR;

PAIR mv[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int DFS(int y, int x, int count)
{
	if (count == 4)
		return map[y][x];

	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + mv[i].first;
		int nx = x + mv[i].second;

		if (0 <= ny && ny < N && 0 <= nx && nx < M && !visit[ny][nx])
		{
			visit[ny][nx] = true;
			sum = max(sum, map[y][x] + DFS(ny, nx, count + 1));
			visit[ny][nx] = false; 
		}
	}

	return sum;
}

int special_shape(int y, int x) // ㅗ,ㅏ,ㅜ,ㅓ 모양
{
	int result = 0;

	if (y >= 1 && x >= 1 && x < M - 1) //ㅗ (현재 좌표 ㅡ의 가운데)
		result = max(result, map[y][x - 1] + map[y][x] + map[y - 1][x] + map[y][x + 1]);
	
	if (y >= 1 && y < N - 1 && x < M - 1) //ㅏ (현재 좌표 ㅣ의 가운데)
		result = max(result, map[y - 1][x] + map[y][x] + map[y][x + 1] + map[y + 1][x]);

	if (y >= 0 && y < N - 1 && x < M - 1) //ㅜ (현재 좌표 ㅡ의 가운데)
		result = max(result, map[y][x - 1] + map[y][x] + map[y + 1][x] + map[y][x + 1]);

	if (y >= 1 && y < N - 1 && x >= 1) //ㅓ (현재 좌표 ㅣ의 가운데)
		result = max(result, map[y - 1][x] + map[y][x] + map[y][x - 1] + map[y + 1][x]);

	return result;
}

int main(void)

{
	init();
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];


	int result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = true;
			result = max(result, DFS(i, j, 1));
			result = max(result, special_shape(i, j));
			visit[i][j] = false;
		}
	}

	cout << result << endl;

	return 0;
}

