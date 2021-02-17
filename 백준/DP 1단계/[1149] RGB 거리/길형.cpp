#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1001

using namespace std;

int N;
int rgb[MAX][3];
int dp[MAX][3]; // [n번째][rgb색상] 저장

int main(void) 
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}
		
	dp[1][0] = rgb[1][0]; // Red 로 시작
	dp[1][1] = rgb[1][1]; // Blue로 시작
	dp[1][2] = rgb[1][2]; // Green으로 시작

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0]; // r(gb,bg)
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1]; // g(rb,br)
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2]; // b(rg,gr)
	}

	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]) << endl;

	return 0;
}
