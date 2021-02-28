import sys
import queue
import copy


def dijkstra(start, Initroute, graph):
    route = copy.deepcopy(Initroute)
    _q = queue.PriorityQueue()
    _q.put((0, start))
    route[start] = 0
    while not _q.empty():
        q_item = _q.get()
        weight, node = q_item

        if route[node] < weight or node not in graph.keys():
            continue

        for neighbor in graph[node]:
            new_weight = weight + graph[node][neighbor]
            if route[neighbor] > new_weight:
                route[neighbor] = new_weight
                _q.put((new_weight, neighbor))

    return route


if __name__=="__main__":
    N, E = map(int, sys.stdin.readline().split())

    #{'5': {'1': '1'}, '1': {'5': '1', '2': '2'}, '2': {'1': '2'}}
    graph = {}
    for _ in range(E):
        u, v, w = map(int, sys.stdin.readline().split())
        if u not in graph.keys():
            graph[u] = {v: w}
        else:
            if v not in graph[u].keys():
                graph[u][v] = w
            else:
                graph[u][v] = min(graph[u][v], w)

        if v not in graph.keys():
            graph[v] = {u: w}
        else:
            if u not in graph[v].keys():
                graph[v][u] = w
            else:
                graph[v][u] = min(graph[v][u], w)

    v1, v2 = map(int, sys.stdin.readline().split())

    route = {node+1: 1e9 for node in range(N)}
    startRoute = dijkstra(1, route, graph)
    v1Route = dijkstra(v1, route, graph)
    v2Route = dijkstra(v2, route, graph)

    #"1 > v1 > v2 > 마지막"과 "1 > v2 > v1 > 마지막"을 비교, 작은 값 출력
    answer = min(startRoute[v1]+v1Route[v2]+v2Route[N], startRoute[v2]+v2Route[v1]+v1Route[N])
    if answer >= 1e9:
        print('-1')
    else:
        print(answer)
