import sys


if __name__=="__main__":
    N, K = map(int, sys.stdin.readline().split(' '))
    coin = []
    dp = [0]*(K+1)

    for _ in range(N):
        coin.append(int(*map(int, sys.stdin.readline().split())))

    dp[0] = 1
    for i in range(N):
        c = coin[i]
        for j in range(c, K+1):
            dp[j] += dp[j-c]

    print(dp[-1])
