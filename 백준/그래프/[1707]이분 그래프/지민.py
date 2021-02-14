import sys
from collections import deque


def bfs(graph, N, start):
    route = deque([start])
    visited = [0 for _ in range(N+1)]
    visited[start] = 1
    color = [0 for _ in range(N+1)]
    color[start] = 1
    stop = 0

    while route:
        s = route.popleft()
        for idx in range(len(graph[s])):
            ns = graph[s][idx]
            if visited[ns] == 0:
                visited[ns] = 1
                color[ns] = color[s] + 1
                route.append(ns)
            else:
                if color[s] == color[ns]:
                    stop += 1
                    return visited, stop

    return visited, stop


if __name__=="__main__":
    T = int(*map(int, sys.stdin.readline().split()))
    answer = []

    for _ in range(T):
        V, E = list(map(int, sys.stdin.readline().split()))
        graph = {}
        for _ in range(E):
            s, e = list(map(int, sys.stdin.readline().split()))
            if s not in graph.keys():
                graph[s] = [e]
            else:
                graph[s].append(e)
            if e not in graph.keys():
                graph[e] = [s]
            else:
                graph[e].append(s)

        #start = min(graph.keys())
        #answer.append(bfs(graph, V, start))
        graphKey = list(graph.keys())
        visited = [0 for _ in range(V+1)]
        ans = 'YES'
        for idx in graphKey:
            if visited[idx] == 0:
                visited, a = bfs(graph, V, idx)
                if a >= 1:
                    ans = 'NO'
                    break
        answer.append(ans)
    print('\n'.join(answer))

