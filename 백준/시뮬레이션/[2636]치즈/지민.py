import sys
from collections import deque


def find_cheese_edge(start, graph):
    route = deque([start])
    visited = [[0]*M for _ in range(N)]
    visited[start[0]][start[1]] = 0

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    find_edge_list, is_cheese = [], False
    while route:
        x, y = route.popleft()
        for idx in range(4):
            nx = x + dx[idx]
            ny = y + dy[idx]

            if not 0<=nx<N or not 0<=ny<M:
                continue

            if graph[nx][ny] == 0 and visited[nx][ny] == 0:
                route.append((nx, ny))
                visited[nx][ny] = 1
            elif graph[nx][ny] == 1 and visited[nx][ny] == 0:
                graph[nx][ny] = 2
                visited[nx][ny] = 1

                is_cheese = True
                find_edge_list.append((nx, ny))

    if is_cheese:
        after_melting_graph, melt_cheese_num = melting_cheese(graph, find_edge_list)
        return is_cheese, after_melting_graph, melt_cheese_num
    else:
        return is_cheese, graph, 0


def melting_cheese(graph, edge_list):
    count_melt_cheese = 0
    for x, y in edge_list:
        graph[x][y] = 0
        count_melt_cheese += 1

    return graph, count_melt_cheese


input = sys.stdin.readline
if __name__ == '__main__':
    N, M = map(int, input().split())    #NxM크기
    cheese_board = [list(map(int, input().split())) for _ in range(N)]

    count_melt_time, melted_cheese = 0, 0
    while True:
        is_melt, melt_cheese, cheese_num = find_cheese_edge((0, 0), cheese_board)
        if not is_melt:
            print(count_melt_time)
            print(melted_cheese)
            break

        count_melt_time += 1
        melted_cheese = cheese_num
