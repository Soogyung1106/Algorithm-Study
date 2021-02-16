#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1000001
#define MOD 15746

int number[MAX];

using namespace std;

void fibo(int N)
{
	number[0] = 0; // X -> 0
	number[1] = 1; // 1 -> 1
	number[2] = 2; // 00 11 -> 2

	for (int i = 3; i <= N; i++)
	{
		number[i] = number[i - 1] + number[i - 2];
		number[i] = number[i] % MOD;
	}
}

int main(void)
{
	long long N;

	cin >> N;

	fibo(N);

	cout << number[N] << endl;

	return 0;
}
