import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    conference = [[] for _ in range(N)]
    using = [0, 0]
    count = 0

    for i in range(N):
        conference[i] = list(map(int, sys.stdin.readline().split()))

    conference = sorted(conference, key=lambda x: [x[1], x[0]])

    for i in range(N):
        start, end = conference[i]
        if using[1] <= start:
            using = [start, end]
            count += 1

    print(count)
