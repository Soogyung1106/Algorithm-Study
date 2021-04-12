import sys
from collections import deque


def find_same_number(start, graph):
    route = deque([start])
    num = graph[start[0]][start[1]]
    visited = []

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    while route:
        x, y = route.popleft()

        for idx in range(4):
            nx, ny = x + dx[idx], y + dy[idx]

            if ny == M:
                ny = 0
            if ny < 0:
                ny = M-1
            if 0<=nx<N and graph[nx][ny] == num and (nx, ny) not in visited:
                route.append((nx, ny))
                visited.append((nx, ny))

    return visited


if __name__=="__main__":
    N, M, T = map(int, sys.stdin.readline().split())
    round_plate = [deque(map(int, sys.stdin.readline().split())) for _ in range(N)]

    for _ in range(T):
        x, d, k = list(map(int, sys.stdin.readline().split()))

        d = 1 if d == 0 else -1

        for temp_x in range(x, N+1, x):
            round_plate[temp_x-1].rotate(d*k)

        is_adj = False
        for i in range(N):
            for j in range(M):
                if round_plate[i][j] == 0:
                    continue
                erase = find_same_number((i, j), round_plate)
                if erase:
                    is_adj = True
                    for tx, ty in erase:
                        round_plate[tx][ty] = 0
                    round_plate[i][j] = 0

        if not is_adj:
            round_plate_temp = sum(map(list, round_plate), [])
            sum_round_plate = sum(round_plate_temp)

            zero_count = round_plate_temp.count(0)
            divide_num = N*M-zero_count
            if divide_num != 0:
                adverage_round_plate = sum_round_plate/divide_num

                for i in range(N):
                    for j in range(M):
                        if round_plate[i][j] == 0:
                            continue
                        if round_plate[i][j] < adverage_round_plate:
                            round_plate[i][j] += 1
                        elif round_plate[i][j] > adverage_round_plate:
                            round_plate[i][j] -= 1
            else:
                break


    print(sum(sum(map(list, round_plate), [])))
