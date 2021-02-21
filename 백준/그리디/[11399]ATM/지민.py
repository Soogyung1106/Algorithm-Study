import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    P = list(map(int, sys.stdin.readline().split(' ')))

    people = sorted(P)

    for i in range(1, N):
        people[i] += people[i-1]

    print(sum(people))
