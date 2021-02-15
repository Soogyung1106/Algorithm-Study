import sys
from collections import deque


def bfs(graph, N, start, end):
    route = deque([start])
    graph[start[0]][start[1]] = 0

    dx = [-2, -2, -1, -1, 1, 1, 2, 2]
    dy = [-1, 1, -2, 2, -2, 2, -1, 1]
    while route:
        x, y = route.popleft()
        if x == end[0] and y == end[1]:
            return graph[x][y]

        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if graph[nx][ny] == 0:
                    graph[nx][ny] = graph[x][y]+1
                    route.append([nx, ny])
    return graph[x][y]


if __name__=="__main__":
    T = int(*map(int, input().split()))
    answer = []

    for _ in range(T):
        I = int(*map(int, sys.stdin.readline().split()))
        chess = [[0]*I for _ in range(I)]
        start = list(map(int, sys.stdin.readline().split()))
        end = list(map(int, sys.stdin.readline().split()))
        if start == end:
            answer.append(0)
        else:
            answer.append(bfs(chess, I, start, end))

    print('\n'.join(map(str, answer)))
