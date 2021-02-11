from collections import deque


def bfs(graph, N, M, start):
    route = deque([start])
    visited = [[0]*N for _ in range(M)]
    graph[start[0]][start[1]] = 0

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    while route:
        x, y = route.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<= nx < M and 0<= ny < N:
                if visited[nx][ny] == 0 and graph[nx][ny] == 1:
                    visited[nx][ny] = 1
                    route.append([nx, ny])
                    graph[nx][ny] = 0

    return graph


if __name__=="__main__":
    T = int(input())
    answer = []

    for _ in range(T):
        data = list(map(int, input().split(' ')))
        if len(data) == 3:
            M, N, K = data
            cabbage = [[0]*N for _ in range(M)]
            for _ in range(K):
                x, y = map(int, input().split(' '))
                cabbage[x][y] = 1

            num = 0
            while True:
                for row in range(M):
                    if 1 in cabbage[row]:
                        start = [row, cabbage[row].index(1)]
                        stop = True
                        break
                    if row == M-1 and 1 not in cabbage[row]:
                        stop = False

                if stop == False:
                    break

                cabbage = bfs(cabbage, N, M, start)
                num += 1

            answer.append(num)

    print('\n'.join(map(str, answer)))


