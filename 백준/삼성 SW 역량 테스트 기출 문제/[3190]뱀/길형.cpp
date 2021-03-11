#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <deque>
#define endl "\n"
#define MAX 101
using namespace std;

typedef struct turn {
	int time;
	char direction;
}turn;

typedef struct coordinate {
	int y;
	int x;
}coordinate;

int answer;
int N, K, L;
int map[MAX][MAX];
deque<turn> dq_turn;
deque<coordinate> snake;

// 위, 아래, 왼쪽, 오른쪽
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

bool check(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N) return false;
	return true;
}

int change(int now, char next)
{
	if (now == 0)
	{
		if (next == 'L') return 2;
		else return 3;
	}
	else if (now == 1)
	{
		if (next == 'L') return 3;
		else return 2;
	}
	else if (now == 2)
	{
		if (next == 'L') return 1;
		else return 0;
	}
	else
	{
		if (next == 'L') return 0;
		else return 1;
	}
}

void move(int count, int direction)
{
	coordinate now;
	now.y = snake[0].y + dy[direction];
	now.x = snake[0].x + dx[direction];

	if (!check(now.y, now.x)) // 범위를 초과하는 경우
	{
		answer = count;
		return;
	}

	for (int i = 0; i < snake.size(); i++)
	{
		if ((now.y == snake[i].y) && (now.x == snake[i].x))
		{
			answer = count;
			return;
		}
	}

	if (map[now.y][now.x] == 1) // 사과가 있을 경우
	{
		map[now.y][now.x] = 0; // 먹음
		snake.push_front(now); // 뱀의 위치
	}
	else  // 사과가 없을 경우
	{
		snake.pop_back(); // 뱀 몸통 사이즈 원래대로
		snake.push_front(now); // 뱀의 위치 
	}

	int next_direction = direction;

	if (!dq_turn.empty() && dq_turn[0].time == count) // 큐에 들어는 것 -> 시간이 되면 방향을 바꿈.
	{
		next_direction = change(direction, dq_turn[0].direction);
		dq_turn.pop_front();
	}

	move(count + 1, next_direction);
}

int main(void)
{
	init();
	cin >> N;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;
		map[y - 1][x - 1] = 1;
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		turn temp;
		int time;
		char dir;
		cin >> time >> dir;

		temp = { time, dir };
		dq_turn.push_back(temp);
	}

	snake.push_back({ 0, 0 });

	move(1, 3);

	cout << answer << endl;

	return 0;
}


