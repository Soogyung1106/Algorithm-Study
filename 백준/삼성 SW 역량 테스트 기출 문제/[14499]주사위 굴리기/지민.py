import sys


def roll_dice(move):
    if move == 0:   #동쪽
        dice[3], dice[2], dice[6], dice[4] = dice[2], dice[6], dice[4], dice[3]
    elif move  == 1:    #서쪽
        dice[3], dice[2], dice[6], dice[4] = dice[4], dice[3], dice[2], dice[6]
    elif move == 2:     #북쪽
        dice[3], dice[5], dice[6], dice[1] = dice[5], dice[6], dice[1], dice[3]
    else:       #남쪽
        dice[3], dice[5], dice[6], dice[1] = dice[1], dice[3], dice[5], dice[6]


if __name__=="__main__":
    N, M, x, y, K = map(int, sys.stdin.readline().split())
    maps = []
    for _ in range(N):
        maps.append(list(map(int, sys.stdin.readline().split())))
    move = list(map(int, sys.stdin.readline().split()))

    #2, 4, 1, 3, 5, 6 > 위 : 3 / 바닥 : 6
    dice = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0}

    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]
    for m in move:
        direction = m-1
        nx = x + dx[direction]
        ny = y + dy[direction]

        if 0 > nx or nx >= N or 0 > ny or ny >= M:
            continue

        x, y = nx, ny
        roll_dice(direction)
        if maps[nx][ny] == 0:
            maps[nx][ny] = dice[6]
        else:
            dice[6] = maps[nx][ny]
            maps[nx][ny] = 0

        print(dice[3])
