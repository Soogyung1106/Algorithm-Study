import sys
from collections import deque

def bfs(graph, N, M):
    route = deque([[1, 0, 0]])
    visited = [[[0]*M for _ in range(N)] for _ in range(2)]
    visited[1][0][0] = 1

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    while route:
        crush, x, y = route.popleft()
        if x == N-1 and y == M-1:
            return visited[crush][x][y]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < M:
                if graph[nx][ny] == 1 and crush == 1:
                    visited[crush-1][nx][ny] = visited[crush][x][y] + 1
                    route.append([0, nx, ny])
                elif graph[nx][ny] == 0 and visited[crush][nx][ny] == 0:
                    visited[crush][nx][ny] = visited[crush][x][y] + 1
                    route.append([crush, nx, ny])
    return -1


if __name__=="__main__":
    N, M = map(int, input().split())
    map = [[0]*M for _ in range(N)]

    for row in range(N):
        rowLine = sys.stdin.readline().split()
        rowLine = ''.join(rowLine)
        for col in range(M):
            map[row][col] = int(rowLine[col])

    bfsResult = bfs(map, N, M)
    print(bfsResult)
