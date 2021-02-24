import sys

if __name__=="__main__":
    T = int(*map(int, sys.stdin.readline().split()))

    for _ in range(T):
        N = int(*map(int, sys.stdin.readline().split()))
        files = list(map(int, sys.stdin.readline().split(' ')))
        dp = [[0]*N for _ in range(N)]
        A = [[0]*N for _ in range(N)]

        sum = [0]
        for i in range(N):
            A[i][i] = i
            sum.append(sum[i] + files[i])

        for z in range(1, N):
            for i in range(N - z):
                j = i + z
                dp[i][j] = sys.maxsize

                for k in range(A[i][j - 1], min(A[i + 1][j] + 1, j)):
                    minn = dp[i][k] + dp[k + 1][j] + sum[j + 1] - sum[i]
                    if dp[i][j] > minn:
                        dp[i][j] = minn
                        A[i][j] = k

        print(dp[0][N-1])
