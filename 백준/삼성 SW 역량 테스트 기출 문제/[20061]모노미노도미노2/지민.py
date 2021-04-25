import sys
from collections import deque


def block_type(type, location):
    _x, _y = location
    if type == 1:
        return [[_x, _y]]
    elif type == 2:
        return [[_x, _y], [_x, _y+1]]
    elif type == 3:
        return [[_x, _y], [_x+1, _y]]


def find_block_location(color, type, location):
    _x, _y = location
    if color == 'green':
        for r in range(6):
            new_block = block_type(type, (r, _y))
            for bx, by in new_block:
                if 0<=bx<=6 and 0<=by<4 and green_board[bx][by] != 0:
                    return r-1
        return 5
    elif color == 'blue':
        for c in range(6):
            new_block = block_type(type, (_x, c))
            for bx, by in new_block:
                if 0 <= bx < 4 and 0 <= by <= 6 and blue_board[bx][by] != 0:
                    return c - 1
        return 5


def move_block_to_green_board(type, location):
    global score
    _x = find_block_location('green', type, location)
    _y = location[1]
    block = block_type(type, (_x, _y))
    for bx, by in block:
        green_board[bx][by] = 1

    for r in range(6):
        if green_board[r] == [1, 1, 1, 1]:
            del green_board[r]
            green_board.appendleft([0, 0, 0, 0])
            score += 1

    special_section_block_count = 0
    for r in range(2):
        if 1 in green_board[r]:
            special_section_block_count += 1
    for _ in range(5, 5-special_section_block_count, -1):
        del green_board[5]
        green_board.appendleft([0, 0, 0, 0])


def move_block_to_blue_board(type, location):
    global score, blue_board
    _x = location[0]
    _y = find_block_location('blue', type, location)
    block = block_type(type, (_x, _y))
    for bx, by in block:
        blue_board[bx][by] = 1

    temp_blue = deque(map(list, zip(*blue_board)))
    for r in range(6):
        if temp_blue[r] == [1, 1, 1, 1]:
            del temp_blue[r]
            temp_blue.appendleft([0, 0, 0, 0])
            score += 1

    special_section_block_count = 0
    for r in range(2):
        if 1 in temp_blue[r]:
            special_section_block_count += 1
    for _ in range(5, 5 - special_section_block_count, -1):
        del temp_blue[5]
        temp_blue.appendleft([0, 0, 0, 0])

    blue_board = deque(map(list, zip(*temp_blue)))


if __name__ == '__main__':
    N = int(*map(int, sys.stdin.readline().split()))
    green_board = deque([0]*4 for _ in range(6))
    green_board.append([5, 5, 5, 5])
    blue_board = deque([0]*6+[5] for _ in range(4))

    score = 0
    for _ in range(N):
        t, x, y = map(int, sys.stdin.readline().split())

        move_block_to_green_board(t, (x, y))
        move_block_to_blue_board(t, (x, y))

    temp_green_string = ''.join(map(str, sum(list(green_board), [])))
    temp_blue_string = ''.join(map(str, sum(list(blue_board), [])))
    block_count = temp_blue_string.count('1') + temp_green_string.count('1')
    print(score)
    print(block_count)
