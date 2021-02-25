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

	while (true)
	{
		stack<char> st;
		bool flag = false;
		string str;
		getline(cin, str);
		
		if (str == ".")
		{
			break;
		}

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '[' || str[i] == '(') st.push(str[i]);
			else if (str[i] == ']')
			{
				if (!st.empty() && st.top() == '[') st.pop();
				else
				{
					flag = true;
					break;
				}
			}
			else if (str[i] == ')')
			{
				if (!st.empty() && st.top() == '(') st.pop();
				else
				{
					flag = true;
					break;
				}
			}
		}

		if (!flag && st.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}
