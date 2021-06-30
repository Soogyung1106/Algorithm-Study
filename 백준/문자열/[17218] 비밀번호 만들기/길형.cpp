#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string str1, str2;

int lcs[1001][1001];

int main()
{
	string tmp1, tmp2;
	cin >> tmp1 >> tmp2;

	// LCS 알고리즘을 위해 앞에 '0'을 붙여준다.
	str1 = '0' + tmp1;
	str2 = '0' + tmp2;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (i == 0 || j == 0)
			{
				lcs[i][j] = 0;
				continue;
			}

			
			if (str1[i] == str2[j]) // 현재 비교하는 값이 서로 같다면, lcs는 + 1
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else // 서로 다르다면 LCS의 값을 왼쪽 혹은 위에서 가져온다.
			{
				if (lcs[i - 1][j] > lcs[i][j - 1])
				{
					lcs[i][j] = lcs[i - 1][j];
				}
				else
				{
					lcs[i][j] = lcs[i][j - 1];
				}
			}
		}
	}

	int i = len1 - 1;
	int j = len2 - 1;
	stack<int> st;

	while (lcs[i][j] != 0)
	{
		// 경로 추적
		// cout << " i :: " << i << " j :: " << j << endl;
		if (lcs[i][j] == lcs[i][j - 1]) j--;
		else if (lcs[i][j] == lcs[i - 1][j]) i--;
		else if (lcs[i][j] - 1 == lcs[i - 1][j - 1])
		{
			st.push(i);
			i--;
			j--;
		}
	}

	while (!st.empty())
	{
		cout << str1[st.top()];
		st.pop();
	}
	return 0;
}
