import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    triangle = [[0]*n for n in range(1, N+1)]
    sum = [[0]*n for n in range(1, N+1)]

    for n in range(N):
        nums = list(map(int, sys.stdin.readline().split()))
        triangle[n] = nums
    sum[0] = triangle[0]

    for n in range(1, N):
        for idx in range(len(triangle[n])):
            if idx == 0:
                sum[n][idx] = triangle[n][idx] + sum[n-1][idx]
            elif idx == len(triangle[n])-1:
                sum[n][idx] = triangle[n][idx] + sum[n-1][idx-1]
            else:
                sum[n][idx] = triangle[n][idx] + max(sum[n-1][idx-1], sum[n-1][idx])

    print(max(sum[N-1]))
