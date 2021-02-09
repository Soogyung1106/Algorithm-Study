def dfs(graph, N, start):
    route = [start]
    visit = [[0] * N for _ in range(N)]
    visit[start[0]][start[1]] = 1
    num = 0

    #상, 하, 좌, 우
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    while route:
        x, y = route.pop()
        if graph[x][y] == 1:
            num += 1
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                #방문한 적 없고, 길이 있을 때
                if visit[nx][ny] == 0 and graph[nx][ny] == 1:
                    visit[x][y] = 1
                    route.append([nx, ny])
                graph[x][y] = 0

    return graph, num

if __name__=="__main__":
    N = int(*map(int, input().split()))
    apartment = [[[] for _ in range(N)] for _ in range(N)]
    dfsResultList = []

    for row in range(N):
        rowLine = str(*map(str, input().split()))
        for col in range(N):
            apartment[row][col] = int(rowLine[col])

    while True:
        for idx in range(N):
            if 1 in apartment[idx]:
                stop = True
                start = [idx, apartment[idx].index(1)]
                break
            if 1 not in apartment[idx] and idx == N-1:
                stop = False

        if stop == False:
            break

        apartment, dfsResult = dfs(apartment, N, start)
        dfsResultList.append(dfsResult)

    print(len(dfsResultList))
    print("\n".join(map(str, sorted(dfsResultList))))
