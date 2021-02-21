#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1002
#pragma warning(disable:4996)
using namespace std;

int dp[MAX][MAX];
/*
풀이내용 참고함.
<기본적인 LIS(Longest Increasing Subsequence) 응용 문제 LIS는 DP의 대표문제>
2차원 배열의 형태로 한쪽에는 가로는 str1 문자열, 세로는 str2 문자열을 기준으로 한다.
엑셀의 표를 보듯이 가로 기준과 세로 기준으로 각각 구하며 기존의 저장된 값에 +1을 하면서 가장 lcs값을 구한다.
*/
int main(void)
{
	freopen("input.txt", "r", stdin);
	
	int i, j;
	string str1, str2;

	cin >> str1 >> str2;

	for (i = 1; i <= str2.size(); i++)
	{
		for (j = 1; j <= str1.size(); j++)
		{
			if (str1.at(j - 1) == str2.at(i - 1))
			{
				dp[i][j] += dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[i - 1][j - 1] << endl;

	return 0;
}
