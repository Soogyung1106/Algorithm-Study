import sys
from collections import deque


def find_ice_section(start, graph):
    route = deque([start])
    visited[start[0]][start[1]] = 1
    count_ice_section = 1

    while route:
        x, y = route.popleft()

        for idx in range(4):
            nx, ny = x + d[idx][0], y + d[idx][1]

            if 0 <= nx < field_len and 0 <= ny < field_len:
                if graph[nx][ny] != 0 and visited[nx][ny] == 0:
                    visited[nx][ny] = visited[x][y] + 1
                    route.append((nx, ny))
                    count_ice_section += 1

    return count_ice_section


if __name__=="__main__":
    N, Q = map(int, sys.stdin.readline().split())
    ice_field = [list(map(int, sys.stdin.readline().split())) for _ in range(2**N)]
    L = list(map(int, sys.stdin.readline().split()))

    field_len = 2**N
    for l in L:
        section_len = 2**l
        section_line = (field_len)//section_len

        separate_idx = [i*section_len for i in range(0, section_line)]
        for section_row in separate_idx:
            row_temp = ice_field[section_row:section_row+section_len]
            new_row = [[] for i in range(0, len(row_temp))]
            for section_column in separate_idx:
                section_temp = [rt[section_column:section_column+section_len] for rt in row_temp]
                section_temp = list(map(list, zip(*section_temp[::-1])))
                for str in range(len(section_temp)):
                    new_row[str].extend(section_temp[str])
            ice_field[section_row:section_row+section_len] = new_row

        d = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        change_field = []
        for r in range(0, field_len):
            for c in range(0, field_len):
                if ice_field[r][c] == 0:
                    continue

                count_ice = 0
                for idx in range(4):
                    nr, nc = r+d[idx][0], c+d[idx][1]
                    if 0 <= nr < field_len and 0 <= nc < field_len:
                        if ice_field[nr][nc] != 0:
                            count_ice += 1

                if count_ice < 3:
                    change_field.append((r, c))

        for r, c in change_field:
            ice_field[r][c] -= 1

    total_ice = sum(sum(ice_field, []))

    visited = [[0]*field_len for _ in range(field_len)]
    max_ice_secion = 0
    for r in range(field_len):
        for c in range(field_len):
            if ice_field[r][c] == 0 or visited[r][c] != 0:
                continue

            ice_section_size = find_ice_section((r, c), ice_field)
            max_ice_secion = max(max_ice_secion, ice_section_size)

    print(total_ice)
    print(max_ice_secion)
