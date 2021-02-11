from collections import deque


def bfs(graph, M, N, H, start):
    route = deque(start)
    day = 1

    dz = [-1, 1, 0, 0, 0 ,0]
    dx = [0, 0, -1, 1, 0, 0]
    dy = [0, 0, 0, 0, -1, 1]
    while route:
        z, x, y = route.popleft()
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]
            if 0 <= nz < H and 0 <= nx < N and 0 <= ny < M:
                if graph[nz][nx][ny] == 0:
                    graph[nz][nx][ny] = graph[z][x][y] + 1
                    route.append([nz, nx, ny])
                    if day < graph[nz][nx][ny]:
                        day = graph[nz][nx][ny]

    return graph, day


if __name__=="__main__":
    M, N, H = map(int, input().split())
    tomatoes = [[[0]*M for _ in range(N)] for _ in range(H)]
    start = []

    for depth in range(H):
        for row in range(N):
            rowLine = list(map(int, input().split(' ')))
            tomatoes[depth][row] = rowLine
            if 1 in rowLine:
                for col in range(M):
                    if rowLine[col] == 1:
                        start.append([depth, row, col])

    bfsResult, day = bfs(tomatoes, M, N, H, start)

    for depth in bfsResult:
        for row in depth:
            if 0 in row:
                day = 0

    print(day-1)
