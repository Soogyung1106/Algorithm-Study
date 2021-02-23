#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#define MAX 501

int arr[MAX];
int dp[MAX][MAX];
int sum[MAX]; // sum[i] = 1 ~ i 까지의 합계

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t, k;
	cin >> t;

	while (t--)
	{
		cin >> k;

		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		memset(sum, 0, sizeof(sum));

		for (int i = 1; i < k + 1; i++)
		{
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		for (int i = 2; i <= k; i++)
		{
			for (int j = i - 1; j > 0; j--)
			{
				dp[j][i] = INT_MAX;

				for (int l = j; l <= i; l++)
				{
					dp[j][i] = min(dp[j][i], dp[j][l] + dp[l + 1][i]);
				}

				dp[j][i] += sum[i] - sum[j - 1];
			}
		}
		cout << dp[1][k] << endl;
	}

	return 0;
}

/*
[소설의 여러 장들이 <연속이 되도록> 파일을 합쳐나가고, 최종적으로는 하나의 파일로 합친다.]

(A+B) + (A+B+C)  VS (B+C)+(A+B+C) 비교한다.

dp[a][c] = min(dp[a][c], dp[a][b] + dp[b+1][c]) 기존 것 vs 새로 분할해서 한 것

dp[1][7] = dp[1][1] + dp[2][7]

dp[1][7] = dp[1][2] + dp[3][7]

dp[1][7] = dp[1][3] + dp[4][7]

dp[1][7] = dp[1][4] + dp[5][7]

dp[1][7] = dp[1][5] + dp[6][7]

dp[1][7] = dp[1][6] + dp[7][7]

중에서 가장 최소값이 되는 것을 넣는다.
*/
