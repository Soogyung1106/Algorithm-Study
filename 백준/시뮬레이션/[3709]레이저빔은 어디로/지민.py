import sys


def find_direction(coordinate):
    _x, _y = coordinate
    if _x == 0:
        return 2
    elif _x == n+1:
        return 0
    elif _y == 0:
        return 1
    elif _y == n+1:
        return 3


def move_laser(start, direction):
    global out_x, out_y
    _x, _y = start
    _x, _y = _x + dx[direction], _y + dy[direction]

    if _x in (0, n+1) or _y in (0, n+1):
        out_x, out_y = str(_x), str(_y)
        return

    if board[_x][_y] != 0:
        new_direction = (direction+1) % 4

        if board[_x][_y] == new_direction:
            out_x, out_y = '0', '0'
            return

        board[_x][_y] = new_direction
        direction = new_direction

    move_laser((_x, _y), direction)


input_func = sys.stdin.readline
if __name__ == '__main__':
    T = int(*map(int, input_func().split()))

    for _ in range(T):
        n, r = map(int, input_func().split())

        board = [[0]*(n+2) for _ in range(n+2)]
        for _ in range(r):
            x, y = map(int, input_func().split())
            board[x][y] = -1

        laser = tuple(map(int, input_func().split()))
        laser_direction = find_direction(laser)

        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        out_x, out_y = -1, -1
        move_laser(laser, laser_direction)
        print(out_x+' '+out_y)
