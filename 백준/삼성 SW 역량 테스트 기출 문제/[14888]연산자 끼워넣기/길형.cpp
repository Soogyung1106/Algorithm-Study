#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <tuple>
#define endl "\n"
#define MAX 12

using namespace std;

typedef tuple<int, int, int, int> TUPLE;

int N;
int maxResult = INT_MIN, minResult = INT_MAX;
int number[MAX];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void DFS(int plus, int minus, int multiply, int divide, int cnt, int sum)

{
	if (cnt == N)
	{
		maxResult = max(maxResult, sum);

		minResult = min(minResult, sum);
	}
	if (plus > 0)
	{
		DFS(plus - 1, minus, multiply, divide, cnt + 1, sum + number[cnt]);
	}
	if (minus > 0)
	{
		DFS(plus, minus - 1, multiply, divide, cnt + 1, sum - number[cnt]);
	}
	if (multiply > 0)
	{
		DFS(plus, minus, multiply - 1, divide, cnt + 1, sum * number[cnt]);
	}
	if (divide > 0)
	{
		DFS(plus, minus, multiply, divide - 1, cnt + 1, sum / number[cnt]);
	}
}

int main(void)

{
	init();
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> number[i];

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	DFS(a, b, c, d, 1, number[0]);


	cout << maxResult << endl;
	cout << minResult << endl;

	return 0;
}
