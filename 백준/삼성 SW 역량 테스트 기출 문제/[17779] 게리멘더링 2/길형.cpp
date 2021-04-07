#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 40
#define MAX_VALUE 987654321

using namespace std;

int N;
int min_count, max_count;
int answer;
int people[MAX][MAX];
int map[MAX][MAX];
int sum[6] = { 0, };

/*
꼭짓점 (x,y) , (x+d1, y-d1), (x+d2, y+d2), (x+d2+d1, y+d2-d1)

1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
*/

void classify(int x, int y, int d1, int d2)
{
	// 5번선거구 지정
	for (int i = 0; i <= d1; i++) 
	{
		map[x + i][y - i] = 5;

		for (int j = y - i; j <= y; j++) 
		{
			map[x + i][j] = 5;
		}
	}

	for (int i = 0; i <= d2; i++) 
	{
		map[x + i][y + i] = 5;

		for (int j = y; j <= y + i; j++) 
		{
			map[x + i][j] = 5;
		}
	}

	for (int i = 0; i <= d2; i++) 
	{
		map[x + d1 + i][y - d1 + i] = 5;
		for (int j = y - d1 + i; j <= y + d2 - d1; j++) 
		{
			map[x + d1 + i][j] = 5;
		}
	}

	for (int i = 0; i <= d1; i++) 
	{
		map[x + d2 + i][y + d2 - i] = 5;
		for (int j = y + d2 - d1; j <= y + d2 - i; j++) 
		{
			map[x + d2 + i][j] = 5;
		}
	}

	// 1번 선거구
	for (int i = 1; i < x + d1; i++) 
	{
		for (int j = 1; j <= y; j++) 
		{
			if (map[i][j] != 5) map[i][j] = 1;
		}
	}

	// 2번선거구
	for (int i = 1; i <= x + d2; i++) 
	{
		for (int j = y + 1; j <= N; j++) 
		{
			if (map[i][j] != 5) map[i][j] = 2;
		}
	}

	// 3번선거구
	for (int i = x + d1; i <= N; i++) 
	{
		for (int j = 1; j < y - d1 + d2; j++) 
		{
			if (map[i][j] != 5) map[i][j] = 3;
		}
	}

	// 4번 선거구
	for (int i = x + d2 + 1; i <= N; i++) 
	{
		for (int j = y - d1 + d2; j <= N; j++) 
		{
			if (map[i][j] != 5) map[i][j] = 4;
		}
	}


	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			int data = map[i][j];
			sum[data] += people[i][j];
		}
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
	cin >> N;

	answer = MAX_VALUE;

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			cin >> people[i][j];
		}
	}

	for (int x = 1; x < N - 1; x++) 
	{
		for (int y = 2; y < N - 1; y++) 
		{
			for (int d1 = 1; d1 < y; d1++) 
			{
				for (int d2 = 1; d2 <= N - y; d2++) 
				{
					classify(x, y, d1, d2);

					int count = 0;

					for (int i = 1; i <= 5; i++) 
					{
						if (sum > 0) count++;
						if (min_count > sum[i]) min_count = sum[i];
						if (max_count < sum[i]) max_count = sum[i];
					}

					if (count == 5)
					{
						int gap = max_count - min_count;

						if (answer > gap) answer = gap;
					}

					min_count = MAX_VALUE;
					max_count = 0;

					memset(map, 0, sizeof(map));
					memset(sum, 0, sizeof(sum));
				}
			}
		}
	}
	cout << answer << endl;

	return 0;
}
