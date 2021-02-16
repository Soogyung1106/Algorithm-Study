#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1000001

using namespace std;

int main(void)
{
	long long number[MAX] = { 0, }; // number 배열에는 횟수가 들어감
	long long N;

	cin >> N;

	while (N > 1) // 0이 들어가 있으면 초기화 상태 그대로임. 연산을 한 횟수를 비교하여 작은 것으로 갱신
	{
		if (number[N - 1] > number[N] + 1 || number[N - 1] == 0) number[N - 1] = number[N] + 1;
		if (N % 2 == 0 && (number[N / 2] > number[N] + 1 || number[N / 2] == 0)) number[N / 2] = number[N] + 1;
		if (N % 3 == 0 && (number[N / 3] > number[N] + 1 || number[N / 3] == 0)) number[N / 3] = number[N] + 1;
		N--;
	}

	cout << number[1];

	return 0;
}
