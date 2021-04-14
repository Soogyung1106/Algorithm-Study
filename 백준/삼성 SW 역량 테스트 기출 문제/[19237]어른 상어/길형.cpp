#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 20
#define SHARK_MAX 401

using namespace std;

typedef struct INFO {
	int shark;
	int left_time;
}INFO;

typedef struct SHARK {
	int y;
	int x;
	int dir;
};

int N, M, K;
int time;
INFO map[MAX][MAX];
SHARK shark[SHARK_MAX];
int priority_dir[SHARK_MAX][5][5];
bool life[SHARK_MAX];

int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };

void SpendTime(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].left_time > 0)
			{
				map[i][j].left_time--; 
			}
		}
	}
}

bool CheckLife(void)
{
	for (int i = 2; i <= M; i++)
	{
		if (!life[i]) return true;
	}

	return false;
}

void MoveShark(void)
{
	SpendTime(); // 냄새 시간 차감

	for (int i = 1; i <= M; i++)
	{
		if (life[i]) continue;

		int y = shark[i].y;
		int x = shark[i].x;
		int dir = shark[i].dir;
		int now_state = 0;

		for (int j = 1; j <= 4; j++)
		{
			int ny = y + dy[priority_dir[i][dir][j]];
			int nx = x + dx[priority_dir[i][dir][j]];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 범위체크
			if (map[ny][nx].shark != 0) continue; // 가려는 곳에 상어의 냄새가 있는지
			
			now_state = 1;
			shark[i].y = ny; // y값 갱신
			shark[i].x = nx; // x값 갱신
			shark[i].dir = priority_dir[i][dir][j]; // 새로운 방향 저장
			break; // 탐색이 아닌, 이동임!!!!!
		}

		if (now_state == 0) // 가려는 곳에 상어 냄새가 있어 자신의 냄새로 가는 경우
		{
			for (int j = 1; j <= 4; j++)
			{
				int ny = y + dy[priority_dir[i][dir][j]];
				int nx = x + dx[priority_dir[i][dir][j]];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 범위체크
				if (map[ny][nx].shark == i)
				{
					shark[i].y = ny; // y값 갱신
					shark[i].x = nx; // x값 갱신
					shark[i].dir = priority_dir[i][dir][j]; // 새로운 방향 저장
					break;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].left_time == 0) // 냄새가 지워지면 정보 초기화
			{
				map[i][j].shark = 0;
			}
		}
	}

	for (int i = 1; i <= M; i++) // 같은 위치에 상어가 여러마리인 경우
	{
		if (life[i]) continue; // 작은 숫자의 상어가 먼저 들어가게끔

		int y = shark[i].y;
		int x = shark[i].x;

		if (map[y][x].left_time == K)
		{
			life[i] = true;
			continue;
		}

		map[y][x].shark = i; // 해당 위치에서 상어 번호 저장
		map[y][x].left_time = K; // 냄새 시간 저장
	}
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
	cin >> N >> M >> K;

	for(int i = 0 ; i <N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			int number;
			cin >> number;
			
			if (number != 0)
			{
				shark[number] = { i,j,0 };
				map[i][j] = { number, K };
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> shark[i].dir;
	}
		
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				cin >> priority_dir[i][j][k];
			}
		}
	}

	while (CheckLife()) // 1번 위치의 상어만 남을 때 까지
	{
		time++;

		if (time > 1000) 
		{
			time = -1;
			break;
		}

		MoveShark();
	}

	cout << time << endl;

	return 0;
}
