#include <iostream>
#define MAX 101
#define MOD 1000000000

using namespace std;

long long dp[MAX][MAX];
/*
1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9
9개 - 0 1 1 1 1 1 1 1 1 1 

10 / 21 / 12, 32 / 23, 43 / 34, 54 / 45, 65 / 56, 76 / 67, 87 / 78, 98 / 89
17개- 1 1 2 2 2 2 2 2 2 1

210 / 321 121 101 / 432 232 212 / 543 343 123 323 / 654 454 234 434 / 765 565 345 545/ 876 676 456 656 / 987 787 567 767 / 898 678 878 / 789 989
32개 - 1 3 3 4 4 4 4 4 3 2
*/
int main()
{
    long long result = 0;
    int N;
    cin >> N;

    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) // i: 수의 자리, j: [i]자리의 마지막 수
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0) // n 끝이 0이 되려면 n-1의 끝숫자가 1인 것
            {
                dp[i][j] = dp[i - 1][j + 1] % MOD;
            }
            else if (j == 9) // n 끝이 9가 되려면 n-1의 끝숫자가 8인 것
            {
                dp[i][j] = dp[i - 1][j - 1] % MOD;
            }
            else // i는 n-1의 i의 i-1,i+1의 숫자만큼
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }  
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        result += dp[N][i];
    }

    cout << (result % MOD) << endl;

    return 0;
}
