#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#define MAX 41
#pragma warning(disable:4996)

using namespace std;

void fibo(int number[MAX])
{
	number[0] = 0;
	number[1] = 1;

	for (int i = 2; i < MAX; i++)
	{
		number[i] = number[i - 1] + number[i - 2];
	}
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	int T;
	int N;
	int number[MAX] = { 0, 1 };

	cin >> T;
	fibo(number);

	while (T--)
	{
		cin >> N;

		if (N == 0)
			cout <<"1 0"<< endl;
		else if (N == 1)
			cout <<"0 1"<< endl;
		else
		{
			cout << number[N - 1] << " "<< number[N] << endl;
		}
	}

	return 0;
}
