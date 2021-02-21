import sys


if __name__=="__main__":
    N, A = map(int, sys.stdin.readline().split())
    coin = [0]*N
    count = 0

    for i in range(N):
        coin[i] = int(*map(int, sys.stdin.readline().split()))

    coin = coin[::-1]
    while A!=0:
        for i in range(N):
            if coin[i] <= A:
                n = A//coin[i]
                A -= (coin[i]*n)
                count += n
                break

    print(count)
