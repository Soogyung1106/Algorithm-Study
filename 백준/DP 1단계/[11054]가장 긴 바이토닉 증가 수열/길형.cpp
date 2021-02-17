#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1001

using namespace std;

/*
이전에 풀었던 가장 긴 증가하는 부분수열을 앞에서 하는 것이랑 뒤에서 하는 것이랑해서
둘의 값을 저장하는 배열을 따로 만들고 Front[i] Back[i]의 합이 가장 큰 것
*/

int main()
{
	int N;
	int number[MAX] = { 0, };
	int front[MAX] = { 0, };
	int back[MAX] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> number[i];
	}

	for (int i = 0; i < N; i++)
	{
		front[i] = 1;
		back[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (number[j] < number[i] && front[j] >= front[i])
			{
				front[i] = front[j] + 1;
			}
		}
	}

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j >= i; j--)
		{
			if (number[j] < number[i] && back[j] >= back[i])
			{
				back[i] = back[j] + 1;
			}
		}
	}

	int answer = front[0] + back[0];

	for (int i = 1; i < N; i++)
	{
		int temp = front[i] + back[i];
		if (temp > answer) answer = temp;
	}

	cout << answer - 1 << endl;

	return 0;
}

