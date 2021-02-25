#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>

#pragma warning(disable:4996)

using namespace std;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	freopen("input.txt", "r", stdin);

	stack<int> st;
	string answer = "";
	int now = 1;
	int n;
	cin >> n;

	while (n--)
	{
		int num;
		cin >> num;

		if (now <= num) // push 가능 아직 기준값인 now보다 도달해야하는 num의 크기가 더 크기 때문
		{
			while (now <= num)
			{
				st.push(now);
				answer += '+';
				now++;
			}
			st.pop();
			answer += '-';
		}
		else // now(기준값)이 num보다 클 때 더이상 push를 할 수 없고 pop만 가능
		{
			if (st.top() < num)
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				st.pop();
				answer += '-';
			}
		}
	}

	for (int j = 0; j < answer.size(); j++)
	{
		cout << answer[j] << "\n";
	}

	return 0;
}
