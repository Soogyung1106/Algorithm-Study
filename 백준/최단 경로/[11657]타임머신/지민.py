import sys


def bellmanFord(start, route, graph):
    route[start] = 0
    for _ in range(len(route)-1):
        for node in graph:
            #1번 정점과 연결되어 있지 않은 경우
            if route[node] == float(1e9):
                continue
            for neighbor in graph[node]:
                new_distance = route[node] + graph[node][neighbor]
                if route[neighbor] > new_distance:
                    route[neighbor] = new_distance

    #최소 경로 검사가 끝났는데 갱신할 값이 존재 > 음수 사이클 존재
    negativeCycle = 0
    for node in graph:
        for neighbor in graph[node]:
            if route[node] == float(1e9):
                continue
            check_distance = route[node] + graph[node][neighbor]
            if route[neighbor] > check_distance:
                negativeCycle = 1

    return negativeCycle, route


if __name__=="__main__":
    N, M = map(int, sys.stdin.readline().split())

    # {'5': {'1': '1'}, '1': {'5': '1', '2': '2'}, '2': {'1': '2'}}
    graph = {}
    for _ in range(M):
        a, b, d = map(int, sys.stdin.readline().split())
        if a not in graph.keys():
            graph[a] = {b: d}
        else:
            if b not in graph[a].keys():
                graph[a][b] = d
            else:
                graph[a][b] = min(graph[a][b], d)

    route = {node + 1: float(1e9) for node in range(N)}
    negative, minRoute = bellmanFord(1, route, graph)

    if negative == 1:
        print('-1')
    else:
        for node in range(2, N+1):
            if minRoute[node] == 1e9:
                print('-1')
            else:
                print(minRoute[node])
