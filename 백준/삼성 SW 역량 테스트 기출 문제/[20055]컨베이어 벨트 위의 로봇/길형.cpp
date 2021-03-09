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

int N, K; // 컨베이어의 길이 N(벨트는 2N), 내구성 0 한도
deque<pair<bool, int>> conveyor;

void rotate(void)
{
	conveyor.push_front(conveyor.back());
	conveyor.pop_back();
}

void put_bot(void)
{
	if (!conveyor.front().first && conveyor.front().second > 0)
	{
		conveyor.front().first = true;
		conveyor.front().second--;
	}
}

void move_bot(void)
{
	for (int i = N - 2; i >= 0; i--)
	{
		if (conveyor[N - 1].first)
		{
			conveyor[N - 1].first = false;
		}
		// 앞 칸에 로봇이 없고 내구도가 0 이상이고, 현재 칸에 로봇이 있으면
		if (!conveyor[i + 1].first && conveyor[i + 1].second > 0 && conveyor[i].first)
		{
			conveyor[i + 1].first = true;
			conveyor[i + 1].second--;
			conveyor[i].first = false;
		}
	}
}

bool checking(void)
{
	int check_zero = 0;

	for (int i = 0; i < conveyor.size(); i++)
	{
		if (conveyor[i].second < 1)
		{
			check_zero++;
		}

		if (check_zero >= K)
		{
			return false;
		}
	}

	return true;
}

void show_print(void)
{
	for (int i = 0; i < conveyor.size(); i++)
	{
		cout << "[" << boolalpha << conveyor[i].first << " " << conveyor[i].second << "] ";
	}
	cout << endl;
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
	int flag = true;
	int time = 0;
	cin >> N >> K;

	for (int i = 0; i < 2 * N; i++)
	{
		int temp;
		cin >> temp;
		conveyor.push_back({ false,temp });
	}

	while (flag)
	{
		time++;
		//cout << "처음 "; show_print();
		rotate(); // 1. 벨트가 한 칸 회전한다
		//cout << "회전 "; show_print();
		move_bot(); // 2.가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
		//cout << "움직 "; show_print();
		put_bot(); // 3. 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
		//cout << "놓기 "; show_print();
		flag = checking(); // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
	}

	cout << time << endl;

	return 0;
}
