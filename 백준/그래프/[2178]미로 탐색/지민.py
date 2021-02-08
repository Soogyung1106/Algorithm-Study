def dfs(graph, N, M, start):
    route = [start]
    visit = [[0] * M for _ in range(N)]
    visit[0][0] = 1

    #상, 하, 좌, 우
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    while route:
        x, y = route.pop(0)
        if x == N-1 and y == M-1:
            return visit
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < M:
                #방문한 적 없고, 길이 있을 때
                if visit[nx][ny] == 0 and graph[nx][ny] == 1:
                    visit[nx][ny] = visit[x][y] + 1
                    route.append([nx, ny])


if __name__=="__main__":
    N, M = map(int, input().split())
    maze = [[[] for _ in range(M)] for _ in range(N)]
    for row in range(N):
        rowLine = str(*map(str, input().split()))
        for col in range(M):
            maze[row][col] = int(rowLine[col])

    dfsResult = dfs(maze, N, M, [0, 0])
    print(dfsResult[N-1][M-1])
