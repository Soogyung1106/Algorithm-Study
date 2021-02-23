#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	int answer = 0;

	for (int i = 1; i <= n; i++)
	{

		int sum = 0;
		string str = to_string(i);

		for (int k = 0; k < str.length(); k++)
		{
			sum += str[k] - '0';
		}

		sum += i;

		if (sum == n)
		{
			answer = i;
			break;
		}
	}
	cout << answer << endl;

	return 0;
}
