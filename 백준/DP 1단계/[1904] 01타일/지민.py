import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    arr = [0] * 1000001
    arr[1] = 1
    arr[2] = 2

    for idx in range(3, N+1):
        arr[idx] = (arr[idx-2]+arr[idx-1])%15746

    print(arr[N])

