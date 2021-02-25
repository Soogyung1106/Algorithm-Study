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

	int n;
	cin >> n;

	vector<int> number(n); // input 숫자를 담아두는 배열
	vector<int> answer(n); // return할 답을 넣어두는 배열
	stack<int> st; // 아직 오큰수를 찾지 못한 index를 담아두는 스택(*)

	for (int i = 0 ; i < n ; i++)
	{
		cin >> number[i];
	}

	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && number[st.top()] < number[i])
		{
			answer[st.top()] = number[i];
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty())
	{
		answer[st.top()] = -1;
		st.pop();
	}

	for (int num : answer)
	{
		cout << num << " ";
	}

	return 0;
}
