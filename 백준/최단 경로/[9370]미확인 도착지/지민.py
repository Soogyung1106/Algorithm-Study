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
    T = int(*map(int, sys.stdin.readline().split()))

    for _ in range(T):
        n, m, t = map(int, sys.stdin.readline().split())
        s, g, h = map(int, sys.stdin.readline().split())

        # {'5': {'1': '1'}, '1': {'5': '1', '2': '2'}, '2': {'1': '2'}}
        graph = {}
        for _ in range(m):
            a, b, d = map(int, sys.stdin.readline().split())
            if a not in graph.keys():
                graph[a] = {b: d}
            else:
                if b not in graph[a].keys():
                    graph[a][b] = d
                else:
                    graph[a][b] = min(graph[a][b], d)

            if b not in graph.keys():
                graph[b] = {a: d}
            else:
                if a not in graph[a].keys():
                    graph[b][a] = d
                else:
                    graph[b][a] = min(graph[b][a], d)

        cadidates = [int(*map(int, sys.stdin.readline().split())) for _ in range(t)]
        route = {node + 1: 1e9 for node in range(n)}
        startRoute = dijkstra(s, route, graph)
        gRoute = dijkstra(g, route, graph)
        hRoute = dijkstra(h, route, graph)

        answer = []
        for c in sorted(cadidates):
            predict = gRoute[h] + min(startRoute[g]+hRoute[c], startRoute[h]+gRoute[c])
            if predict == startRoute[c]:
                answer.append(c)

        print(' '.join(map(str, answer)))
