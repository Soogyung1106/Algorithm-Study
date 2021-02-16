import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    stair = []
    score = [0]*N

    for _ in range(N):
        s = int(*map(int, sys.stdin.readline().split()))
        stair.append(s)

    if N >= 1:
        score[0] = stair[0]
    if N >= 2:
        score[1] = stair[0] + stair[1]
    if N >= 3:
        score[2] = stair[2]+max(stair[0], stair[1])

    for n in range(3, N):
        score[n] = stair[n] + max(score[n-3]+stair[n-1], score[n-2])

    print(score[N-1])
