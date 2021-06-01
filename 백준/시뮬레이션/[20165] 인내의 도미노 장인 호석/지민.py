import sys


def attack(coordinate, d, _board):
    _x, _y = coordinate
    if _board[_x][_y] == 'F':
        return _board, 0

    _score = 0
    count = game_board[_x][_y]
    while count:

        if not 0<=_x<N or not 0<=_y<M:
            break

        if _board[_x][_y] == 'S':
            _board[_x][_y] = 'F'
            _score += 1

            count = max(count, game_board[_x][_y])

        _x, _y = _x + dx[d], _y + dy[d]
        count -= 1

    return _board, _score


def defend(coordinate, _board):
    _x, _y = coordinate
    _board[_x][_y] = 'S'

    return _board


input_func = sys.stdin.readline
if __name__ == '__main__':
    N, M, R = map(int, input_func().split())
    game_board = [list(map(int, input_func().split())) for _ in range(N)]

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    direction = {'E': 0, 'W': 1, 'S': 2, 'N': 3}
    moving_board, attack_score = [['S']*M for _ in range(N)], 0
    for _ in range(R):
        attack_x, attack_y, attack_d = map(str, input_func().split())
        attack_x, attack_y, attack_d = int(attack_x)-1, int(attack_y)-1, direction[attack_d]

        moving_board, score = attack((attack_x, attack_y), attack_d, moving_board)

        defend_x, defend_y = map(int, input_func().split())
        defend_x, defend_y = defend_x-1, defend_y-1
        
        moving_board = defend((defend_x, defend_y), moving_board)

        attack_score += score


    print(attack_score)
    for idx in range(N):
        print(' '.join(map(str, moving_board[idx])))
