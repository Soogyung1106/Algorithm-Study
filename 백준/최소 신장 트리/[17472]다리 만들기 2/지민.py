import sys
from collections import deque


#bfs로 찾아가면서 라벨링
def set_island(start, N, M, graph, label):
    visited = [[0]*M for _ in range(N)]
    visited[start[0]][start[1]] = 1
    route = deque([start])

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    while route:
        x, y = route.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            graph[x][y] = label
            if 0<=nx<N and 0<=ny<M:
                if visited[nx][ny] == 0 and graph[nx][ny] == 1:
                    graph[nx][ny] = label
                    route.append([nx, ny])

    return graph


#섬간 거리 구하기
def get_island_distance(graph, N, M):
    #가로 기준, 세로 기준
    _islands = [graph, list(map(list, zip(*graph)))]

    for direct in range(2):
        for x in range(len(_islands[direct])):
            sd, d, start, end = -1, 0, 0, 0
            for y in range(1, len(_islands[direct][0])):
                #섬 | 바다
                if _islands[direct][x][y] == 0 and _islands[direct][x][y-1] != 0:
                    sd = y-1
                    start = _islands[direct][x][y-1]
                #바다 | 섬
                if _islands[direct][x][y] != 0 and _islands[direct][x][y-1] == 0 and sd != -1:
                    if _islands[direct][x][y] == start:
                        continue
                    d = y-sd-1
                    end = _islands[direct][x][y]

                    if d <= 1 or start == 0 or end == 0:
                        continue

                    #거리 등록
                    if distance[start][end] > d or distance[end][start] > d:
                        distance[start][end] = d
                        distance[end][start] = d
                        sd, d, start, end = -1, 1, 0, 0

    return distance


#kruskal
def find_parent(node):
    if parent[node] == node:
        return node

    parent[node] = find_parent(parent[node])
    return parent[node]


def union(node_u, node_v):
    root_u = find_parent(node_u)
    root_v = find_parent(node_v)

    if root_u == root_v:
        return False

    if root_u < root_v:
        parent[root_v] = root_u
    else:
        parent[root_u] = root_v
    return True


def kruskal(graph):
    sumDistance = 0
    for s, e, d in graph:
        if union(s, e):
            sumDistance += d

    return sumDistance


if __name__=="__main__":
    N, M = map(int, sys.stdin.readline().split())

    island = [list(map(int, sys.stdin.readline().split(' '))) for _ in range(N)]

    #라벨링
    label = 2   #섬이 1이니까 다른 번호 2부터 라벨링(1로 하면 무한루프)
    for r in range(N):
        for c in range(M):
            if island[r][c] == 1:
                start = [r, island[r].index(1)]
                island = set_island(start, N, M, island, label)
                label += 1

    distance = {n1: {n2 : 1e9 for n2 in range(2, label)} for n1 in range(2, label)}
    for idx in range(2, label):
        distance[idx][idx] = 0

    #섬 사이의 거리
    island_distance = {}
    island_distance = get_island_distance(island, N, M)

    #섬 사이의 다리
    island_bridges = []
    for s in island_distance:
        for d in island_distance[s]:
            #if s == d or (d, s, island_distance[d][s]) in island_bridges or island_distance[s][d] == 1e9:
            if s == d or island_distance[s][d] == 1e9:
                continue
            island_bridges.append((s, d, island_distance[s][d]))

    island_bridges.sort(key=lambda x: x[2])

    parent = {idx: idx for idx in range(2, label)}
    answer = kruskal(island_bridges)

    root = []
    for idx in parent:
        root_idx = find_parent(idx)
        root.append(root_idx)

    value = root[0]
    if all(x == value for x in root):
        print(answer)
    else:
        print('-1')
