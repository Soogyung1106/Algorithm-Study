import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    wine = [0]
    drink = [0]*(N+1)

    for _ in range(N):
        wine.extend(map(int, sys.stdin.readline().split()))

    if 1 <= N:
        drink[0:2] = 0, wine[1]
    if 2 <= N:
        drink[2] = wine[1]+wine[2]

    for n in range(3, N+1):
        drink[n] = max(wine[n]+wine[n-1]+drink[n-3], wine[n]+drink[n-2], drink[n-1])

    print(max(drink))
