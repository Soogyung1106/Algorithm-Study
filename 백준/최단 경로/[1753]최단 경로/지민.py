import sys
import queue


def dijkstra(start, route, graph):
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
    V, E = map(int, sys.stdin.readline().split())
    start = int(sys.stdin.readline())

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

    route = {node+1: 1e9 for node in range(V)}
    minRoute = dijkstra(start, route, graph)

    for i in range(V):
        if minRoute[i+1] == 1e9:
            minRoute[i+1] = 'INF'
        print(str(minRoute[i+1]))
