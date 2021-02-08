def dfs(graph, start):
    visited = []
    node = [start]

    while node:
        s = node.pop()
        if s not in visited:
            visited.append(s)
            if s in graph.keys():
                node.extend(graph[s])
    return visited

def bfs(graph, start):
    visited = []
    node = [start]

    while node:
        s = node.pop(0)
        if s not in visited:
            visited.append(s)
            if s in graph.keys():
                node.extend(graph[s])
    return visited

if __name__=="__main__":
    N, M, V = map(int, input().split())
    graph = {}
    for __ in range(M):
        s, e = map(int, input().split())
        if s in graph.keys():
            graph[s].append(e)
        else:
            graph[s] = [e]

        if e in graph.keys():
            graph[e].append(s)
        else:
            graph[e] = [s]
        graph[s] = sorted(graph[s], reverse=True)
        graph[e] = sorted(graph[e], reverse=True)

    dfsResult = dfs(graph, V)
    print(' '.join(map(str, dfsResult)))
    for g in graph:
        graph[g].sort()

    bfsResult = bfs(graph, V)
    print(' '.join(map(str, bfsResult)))
