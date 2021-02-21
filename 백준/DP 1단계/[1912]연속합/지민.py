import sys


if __name__=="__main__":
    n = int(*map(int, sys.stdin.readline().split()))
    N = list(map(int, sys.stdin.readline().split(' ')))
    sum = [0]*n
    sum[0] = N[0]

    for i in range(1, n):
        sum[i] = max(sum[i-1], 0) + N[i]

    print(max(sum))
