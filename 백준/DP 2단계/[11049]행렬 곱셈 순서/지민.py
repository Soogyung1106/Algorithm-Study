#PyPy3

import sys

if __name__=="__main__":
    N= int(*map(int, sys.stdin.readline().split()))
    arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
    dp = [[0]*N for _ in range(N)]

    for z in range(1, N):
        for i in range(N-z):
            j = i + z
            dp[i][j] = sys.maxsize

            for k in range(i, j):
                count = dp[i][k]+dp[k+1][j]+arr[i][0] * arr[k][1] * arr[j][1]
                if count < dp[i][j]:
                    dp[i][j] = count

    print(dp[0][N-1])
