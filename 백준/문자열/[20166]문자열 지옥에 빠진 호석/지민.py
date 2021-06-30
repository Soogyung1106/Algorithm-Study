import sys
from collections import defaultdict


def make_strings(start, _depth, _string):
    x, y = start
    if _depth == 5:
        return

    string_dict[_string] += 1

    for dirc in range(8):
        nx = (x + dx[dirc])%N
        ny = (y + dy[dirc])%M

        make_strings((nx, ny), _depth+1, _string+world[nx][ny])


input_func = sys.stdin.readline
if __name__ == '__main__':
    N, M, K = map(int, input_func().split())
    world = [list(*map(str, input_func().split())) for _ in range(N)]

    dx = [-1, -1, 0, 1, 1, 1, 0, -1]
    dy = [0, 1, 1, 1, 0, -1, -1, -1]
    string_dict = defaultdict(int)
    for r in range(N):
        for c in range(M):
            make_strings((r, c), 0, world[r][c])

    for _ in range(K):
        god_string = str(*map(str, input_func().split()))
        print(string_dict[god_string])
