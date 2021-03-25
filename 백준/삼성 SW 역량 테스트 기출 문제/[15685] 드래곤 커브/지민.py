import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    maps = [[0]*101 for _ in range(101)]

    dx = [1, 0, -1, 0]
    dy = [0, -1, 0, 1]
    for _ in range(N):
        x, y, d, g = map(int, sys.stdin.readline().split())
        maps[x][y] = 1
        direction, temp = [d], [d]
        for _ in range(g+1):
            for idx in direction:
                x += dx[idx]
                y += dy[idx]
                maps[x][y] = 1

            #다음 세대 방향
            direction = [(i+1) % 4 for i in temp]
            direction.reverse()
            temp += direction

    count = 0
    for r in range(100):
        for c in range(100):
            if maps[r][c] and maps[r][c+1] and maps[r+1][c] and maps[r+1][c+1]:
                count += 1

    print(count)
