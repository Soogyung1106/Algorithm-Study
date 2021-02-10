from collections import deque

def bfs(graph, N, M, start):
    route = deque(start)
    day = 1

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    while route:
        tx, ty = route.popleft()
        for i in range(4):
            nx, ny = tx + dx[i], ty + dy[i]
            if 0 <= nx < N  and 0 <= ny < M:
                if graph[nx][ny] == 0:
                    graph[nx][ny] = graph[tx][ty] + 1
                    route.append([nx, ny])
                    if day < graph[nx][ny]:
                        day = graph[nx][ny]

    return graph, day

if __name__=="__main__":
    M, N = map(int, input().split())
    tomatoes = [[] for _ in range(N)]

    for row in range(N):
        rowLine = list(map(int, input().split(' ')))
        tomatoes[row] = rowLine

    startList = []
    for row in range(len(tomatoes)):
        for col in range(len(tomatoes[row])):
            if tomatoes[row][col] == 1:
                startList.append([row, col])

    bfsResult, day= bfs(tomatoes, N, M, startList)

    for result in bfsResult:
        if 0 in result:
            day = 0

    print(day-1)
