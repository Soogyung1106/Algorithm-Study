import sys


if __name__=="__main__":
    N, K = map(int, sys.stdin.readline().split())
    object = [[0, 0] for _ in range(N+1)]
    backpack = [[0]*(K+1) for _ in range(N+1)]

    for i in range(1, N+1):
        object[i] = list(map(int, sys.stdin.readline().split()))

    for i in range(1, N+1):
        w, v = object[i]
        for j in range(1, K+1):
            if j < w:
                backpack[i][j] = backpack[i - 1][j]
            else:
                backpack[i][j] = max(backpack[i - 1][j], backpack[i - 1][j - w] + v)

    print(backpack[N][K])
