import sys
from itertools import combinations
from collections import deque


#bfs
def spread_virus(start, graph):
    route = deque(start)
    visited = [[-1]*N for _ in range(N)]
    for s in start:
        visited[s[0]][s[1]] = 0
    max_time = 0

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    while route:
        x, y = route.popleft()

        for idx in range(4):
            nx, ny = x + dx[idx], y + dy[idx]

            if 0<=nx<N and 0<=ny<N and visited[nx][ny] == -1:
                if graph[nx][ny] != 1:
                    visited[nx][ny] = visited[x][y]+1
                    route.append((nx, ny))
                    if graph[nx][ny] == 0:
                        max_time = max(max_time, visited[nx][ny])

    return visited, max_time


if __name__=="__main__":
    N, M = map(int, sys.stdin.readline().split())
    lab, virus_possibility, block_cnt = [], [], 0
    for r in range(N):
        lab_input_temp = list(map(int, sys.stdin.readline().split()))
        lab.append(lab_input_temp)
        for c in range(N):
            if lab_input_temp[c] == 2:
                virus_possibility.append((r, c))
            elif lab_input_temp[c] == 1:
                block_cnt += 1

    virus_possible_combination = list(combinations(virus_possibility, M))
    min_time = sys.maxsize
    lab_temp = [r[:] for r in lab]
    for vpc in virus_possible_combination:
        virus_lab, time = spread_virus(vpc, lab_temp)
        virus_lab_sum = sum(virus_lab, [])
        #방문하지 않은 곳과 벽의 갯수가 불일치 == 모든 칸에 바이러스 확산 불가
        if virus_lab_sum.count(-1) != block_cnt:
            continue
        min_time = min(min_time, time)

    print(min_time if min_time!=sys.maxsize else -1)
