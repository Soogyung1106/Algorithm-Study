#시간 감축 필요
import sys
from collections import deque


def find_union(start, graph):
    route = deque([start])
    visited[start[0]][start[1]] = 1
    _union = [start]
    _population = graph[start[0]][start[1]]
    union_flag = False

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    while route:
        x, y = route.popleft()

        for idx in range(4):
            nx = x + dx[idx]
            ny = y + dy[idx]

            if 0<=nx<N and 0<=ny<N and visited[nx][ny] == 0:
                #연합이면
                if L<=abs(graph[x][y]-graph[nx][ny])<=R:
                    route.append([nx, ny])
                    visited[nx][ny] = 1
                    #연합
                    _union.append([nx, ny])
                    _population += graph[nx][ny]
                    union_flag = True

    if len(_union) == 1:
        return union_flag, graph
    else:
        _union_population = int(_population/len(_union))
        for idx in _union:
            x, y = idx
            graph[x][y] = _union_population

    return union_flag, graph


if __name__=="__main__":
    N, L, R = map(int, sys.stdin.readline().split())
    A = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    count = 0
    while True:
        flag = False
        #연합여부 검사
        visited = [[0] * N for _ in range(N)]
        for r in range(N):
            for c in range(N):
                if visited[r][c] == 0:
                    flag_temp, A = find_union([r, c], A)
                    if flag_temp == True and flag == False:
                            flag = flag_temp

        if flag == False:
            break
        else:
            count += 1

    print(count)
