#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>

#pragma warning(disable:4996)

using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	stack<int> st;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			if (st.empty()) continue;
			else st.pop();
		}
		else
		{
			st.push(temp);
		}
	}

	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}

	cout << sum;

	return 0;
}
