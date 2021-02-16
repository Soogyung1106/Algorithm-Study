import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    house = []
    color = [[0]*3 for _ in range(N)]

    for _ in range(N):
        R, G, B = map(int, sys.stdin.readline().split())
        house.append([R, G, B])
    color[0] = house[0]

    for h in range(1, N):
        color[h][0] = house[h][0] + min(color[h-1][1], color[h-1][2])
        color[h][1] = house[h][1] + min(color[h-1][0], color[h-1][2])
        color[h][2] = house[h][2] + min(color[h-1][0], color[h-1][1])

    print(min(color[N-1]))
