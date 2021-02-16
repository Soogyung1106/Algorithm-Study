#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 101
#pragma warning(disable:4996)
long long number[MAX] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

using namespace std;

void fibo(int N)
{
	for (int i = 11; i <= N; i++)
	{
		if (number[i] == 0) number[i] = number[i - 2] + number[i - 3];
	}
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	int T, N;

	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		fibo(N);

		cout << number[N] << endl;
	}

	return 0;
}
