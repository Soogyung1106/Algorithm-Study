import sys
from collections import deque
from itertools import combinations


def separated_virus(start, N, M, graph):
    route = deque(start)

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    while route:
        x, y = route.popleft()

        for idx in range(4):
            nx = x + dx[idx]
            ny = y + dy[idx]

            if 0<=nx<N and 0<=ny<M:
                if graph[nx][ny] == 0:
                    graph[nx][ny] = 2
                    route.append([nx, ny])


if __name__=="__main__":
    N, M = map(int, sys.stdin.readline().split())
    map = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    zeros, virus = [], []
    for r in range(N):
        for c in range(M):
            if map[r][c] == 0:
                zeros.append([r, c])
            elif map[r][c] == 2:
                virus.append([r, c])

    answer = 0
    for comb in combinations(zeros, 3):
        map_temp = [r[:] for r in map]
        # 벽 세우기
        for c in comb:
            map_temp[c[0]][c[1]] = 1

        # 바이러스 퍼뜨리기
        separated_virus(virus, N, M, map_temp)

        # 0 세기
        map_count = sum(map_temp, [])
        answer = max(answer, map_count.count(0))

    print(answer)
