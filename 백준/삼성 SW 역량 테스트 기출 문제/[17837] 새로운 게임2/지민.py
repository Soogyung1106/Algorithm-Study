import sys
from collections import defaultdict


if __name__ == '__main__':
    N, K = map(int, sys.stdin.readline().split())
    chess_board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
    chess_pieces, pieces_count = defaultdict(dict), defaultdict(list)
    for idx in range(K):
        r, c, d = map(int, sys.stdin.readline().split())
        chess_pieces[idx] = {'location': (r-1, c-1), 'direction': d-1}
        pieces_count[(r-1, c-1)].append(idx)

    directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]
    change_directions = {0: 1, 1: 0, 2: 3, 3: 2}

    play_count = 1
    break_flag = False
    while True:
        if play_count > 1000:
            play_count = -1
            break

        for id in range(K):
            (r, c), d = chess_pieces[id].values()

            move_piece_index = pieces_count[(r, c)].index(id)
            move_pieces = pieces_count[(r, c)][move_piece_index:]
            if pieces_count[(r, c)][:move_piece_index]:
                pieces_count[(r, c)] = pieces_count[(r, c)][:move_piece_index]
            else:
                pieces_count.pop((r, c))

            dr = r + directions[d][0]
            dc = c + directions[d][1]
            if (0 <= dr < N and 0 <= dc < N) and chess_board[dr][dc] != 2:
                if chess_board[dr][dc] == 1:
                    move_pieces = move_pieces[::-1]

                pieces_count[(dr, dc)].extend(move_pieces)
                for mp in move_pieces:
                    chess_pieces[mp]['location'] = (dr, dc)
            else:
                cd = change_directions[d]
                chess_pieces[id]['direction'] = cd
                dr = r + directions[cd][0]
                dc = c + directions[cd][1]
                if (0 <= dr < N and 0 <= dc < N) and chess_board[dr][dc] != 2:
                    if chess_board[dr][dc] == 1:
                        move_pieces = move_pieces[::-1]

                    pieces_count[(dr, dc)].extend(move_pieces)
                    for mp in move_pieces:
                        chess_pieces[mp]['location'] = (dr, dc)
                else:
                    dr, dc = r, c
                    pieces_count[(dr, dc)].extend(move_pieces)

            if len(pieces_count[(dr, dc)]) >= 4:
                break_flag = True
                break

        if break_flag:
            break

        play_count += 1

    print(play_count)
