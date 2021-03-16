import sys


def dfs(start, N, M, graph):
    route = [start]
    count = 1
    graph[start[0]][start[1]] = 2

    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    while route:
        x, y, d = route.pop()
        nd = d

        for idx in range(4):
            nd = (nd+3)%4
            nx = x + dx[nd]
            ny = y + dy[nd]

            if 0<=nx<N and 0<=ny<M:
                if graph[nx][ny] == 0:
                    route.append([nx, ny, nd])
                    graph[nx][ny] = 2
                    count += 1
                    break

            #네 방향 모두 탐색 후
            if idx == 3:
                bd = (d+2)%4
                bx = x + dx[bd]
                by = y + dy[bd]
                if graph[bx][by] == 1:
                    return count
                else:
                    route.append([bx, by, d])


if __name__=="__main__":
    N, M = map(int, sys.stdin.readline().split())
    r, c, d = map(int, sys.stdin.readline().split())
    map = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    answer = dfs([r, c, d], N ,M, map)
    print(answer)
