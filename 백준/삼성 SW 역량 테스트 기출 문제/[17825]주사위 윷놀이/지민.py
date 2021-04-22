import sys


def move_tokens(times, score, _tokens):
    global max_score
    if times == 10:
        max_score = max(max_score, score)
        return

    for token in range(4):
        r, c = _tokens[token]
        if (r, c) == (-1, -1):
            continue

        nr, nc = r, c+dice[times]
        #짧은 줄에서 넘어갈 때
        board_line_length = len(yut_board[nr])
        if 1 <= r <= 3 and nc >= board_line_length:
                nr = 4
                nc -= (board_line_length-1)
        
        #도착했을 때
        if nc >= len(yut_board[nr]) or (nr, nc) == (5, 1):
            _tokens[token] = [-1, -1]
            move_tokens(times+1, score, _tokens)
            _tokens[token] = [r, c]
            continue
        else:
            if (nr, nc) == (0, 5):
                nr, nc = 1, 0
            elif (nr, nc) == (0, 10):
                nr, nc = 2, 0
            elif (nr, nc) == (0, 15):
                nr, nc = 3, 0
            elif yut_board[nr][nc] == 25:
                nr, nc = 4, 0
            elif nr != 5 and nc == len(yut_board[nr])-1:
                nr, nc = 5, 0

            if [nr, nc] in _tokens:
                continue

            _tokens[token] = [nr, nc]
            move_tokens(times+1, score+yut_board[nr][nc], _tokens)
            _tokens[token] = [r, c]


if __name__ == '__main__':
    dice = list(map(int, sys.stdin.readline().split()))
    yut_board = [[0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40],
                 [10, 13, 16, 19, 25],
                 [20, 22, 24, 25],
                 [30, 28, 27, 26, 25],
                 [25, 30, 35, 40],
                 [40, 0]]
    tokens = [[0, 0], [0, 0], [0, 0], [0, 0]]

    max_score = 0
    move_tokens(0, 0, tokens)
    print(max_score)
