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
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		int sum = 0;

		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(') sum++;
			else if (str[j] == ')') sum--;

			if (sum < 0)
			{
				break;
			}
		}

		if (sum == 0) cout << "YES" << endl;
		else if(sum != 0) cout << "NO" << endl;
	}

	return 0;
}
