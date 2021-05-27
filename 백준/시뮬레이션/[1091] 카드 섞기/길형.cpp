#include <vector>
#include <iostream>
#define MAX 50
#define endl "\n";
using namespace std;

int idx[MAX];
int copy_idx[MAX];
int init_state[MAX];
int suffle[MAX];
int N;

bool Check()
{
	for (int i = 0; i < N; i++)
	{
		if (idx[i] != (i % 3))
		{
			return false;
		}
	}
		
	return true;
}

void SuffleCard()
{
	int cnt = 0;

	while (!Check())
	{
		cnt++;

		// 카드 섞기
		for (int i = 0; i < N; i++)
		{
			copy_idx[i] = idx[i];
		}

		for (int i = 0; i < N; i++)
		{
			idx[suffle[i]] = copy_idx[i];
		}

		// 카드가 섞기 전 맨 처음 상태인지 확인
		for (int i = 0; i < N; i++)
		{
			if (init_state[i] != idx[i])
				break;

			if (i == N - 1)
			{
				// 싸이클이 발생, 아무리 섞어도 종료 조건을 충족하지 못함
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << cnt << endl;
}

void init(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> idx[i];
		init_state[i] = idx[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> suffle[i];
	}

	SuffleCard();

	return 0;
}
