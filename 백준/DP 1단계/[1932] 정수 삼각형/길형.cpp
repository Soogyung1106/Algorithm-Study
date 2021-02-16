#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

int main()
{
	int N;
	int temp;
	int answer = 0;

	cin >> N;

	vector<vector<int>> result(N, vector<int>(N, 0)); // N x N 정사각형 벡터 배열

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j <= i; j++) 
		{
			cin >> temp;
			result[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++) 
	{
		if (i != 0)
		{
			result[i][0] += result[i - 1][0];
		}
		for (int j = 1; j <= i; j++) 
		{
			temp = result[i - 1][j - 1] > result[i - 1][j] ? result[i - 1][j - 1] : result[i - 1][j];
			result[i][j] += temp;
		}
	}

	for (int i = 0; i < N; i++) 
	{
		if (answer < result[N - 1][i])
		{
			answer = result[N - 1][i];
		}
	}

	cout << answer << endl;

	return 0;
}
