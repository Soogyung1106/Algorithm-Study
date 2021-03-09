#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <deque>
#define endl "\n"

using namespace std;

deque<int> gear[4];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void rotate(int index, int direction)
{
	if (index < 0 || index >= 4) return;

	if (direction == 1) // 시계방향
	{
		int temp = gear[index].back();
		gear[index].pop_back();
		gear[index].push_front(temp);
	}
	else
	{
		int temp = gear[index].front();
		gear[index].pop_front();
		gear[index].push_back(temp);
	}
}

void right_side(int index, int direction)
{
	if (index + 1 > 3) return;

	if (gear[index][2] != gear[index + 1][6])
	{
		right_side(index + 1, -direction);
		rotate(index + 1, -direction);
	}
}

void left_side(int index, int direction)
{
	if (index - 1 < 0) return;

	if (gear[index][6] != gear[index - 1][2])
	{
		left_side(index - 1, -direction);
		rotate(index - 1, -direction);
	}
}

int main(void)
{
	init();
	int K;
	int answer = 0;

	for (int i = 0; i < 4; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < 8; j++)
		{
			gear[i].push_back(temp[j]-'0'); // 0 : N, 1 : S
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int gear_num, direction; // 톱니바퀴 번호, 방향(1 : 시계방향, -1 : 반시계방향)
		cin >> gear_num >> direction;

		left_side(gear_num-1, direction);
		right_side(gear_num-1, direction);
		rotate(gear_num - 1, direction);
	}

	for (int i = 0; i < 4; i++)
	{
		if (gear[i][0] == 1) answer += pow(2, i);
	}
	
	cout << answer << endl;

	return 0;
}
