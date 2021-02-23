#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

int card[101];

int main(void)
{
	int res = -1;
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
	}
		
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int sum = 0;

				sum += card[i] + card[j] + card[k];

				if (sum <= M) res = max(res, sum);
			}
		}
	}
	cout << res;

	return 0;
}
