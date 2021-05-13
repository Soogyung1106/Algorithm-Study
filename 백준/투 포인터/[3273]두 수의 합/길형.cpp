#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 1000000

using namespace std;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	int N, X;
	int answer = 0;
	vector<int> number;

	init();
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		number.push_back(temp);
	}

	cin >> X;

	sort(number.begin(), number.end());

	int start = 0, end = N-1;
	
	while (start < end)
	{
		int sum = number[start] + number[end];

		if (sum == X)
		{
			start++;
			end--;
			answer++;
		}
		else if (sum > X)
		{
			end--;
		}
		else
		{
			start++;
		}
	}

	cout << answer;

	return 0;
}
