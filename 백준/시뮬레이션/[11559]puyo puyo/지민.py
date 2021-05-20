import sys
from collections import deque


def find_puyo_group(start, puyo_color, graph):
    route = deque([start])

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    puyo_group_list = []
    while route:
        x, y = route.popleft()
        for idx in range(4):
            nx = x + dx[idx]
            ny = y + dy[idx]

            if not 0<=nx<12 or not 0<=ny<6:
                continue

            if graph[nx][ny] == puyo_color and visited[nx][ny] == 0:
                route.append((nx, ny))
                visited[nx][ny] = 1
                puyo_group_list.append((nx, ny))

    if puyo_group_list:
        puyo_group_list.append(start)
        return puyo_group_list
    else:
        return None


def erase_and_move_puyo_group(erase_list, graph):
    for x, y in erase_list:
        graph[x][y] = '.'

    _graph = list(map(list, zip(*graph)))
    for idx in range(6):
        empty_line = ['.'] * _graph[idx].count('.')
        _graph[idx] = empty_line + [puyo for puyo in _graph[idx] if puyo != '.']
    graph = list(map(list, zip(*_graph)))

    return graph


input = sys.stdin.readline
if __name__ == '__main__':
    puyo_field = [list(*map(list, input().split())) for _ in range(12)]

    temp_field = [r[:] for r in puyo_field]
    count = 0
    while True:
        erase_puyo_list = []
        visited = [[0] * 6 for _ in range(12)]
        for r in range(12):
            for c in range(6):
                if temp_field[r][c] == '.':
                    continue

                visited[r][c] = 1
                puyo_group = find_puyo_group((r, c), temp_field[r][c], temp_field)
                if puyo_group and len(puyo_group) >= 4:
                    erase_puyo_list.extend(puyo_group)

        if erase_puyo_list:
            temp_field = erase_and_move_puyo_group(erase_puyo_list, temp_field)
            count += 1

        else:
            print(count)
            break
