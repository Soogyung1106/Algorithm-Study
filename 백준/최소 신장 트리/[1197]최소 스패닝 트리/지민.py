import sys


def find(node):
    if parent[node] == node:
        return node

    parent[node] = find(parent[node])
    return parent[node]


def union(node_1, node_2):
    root_1 = find(node_1)
    root_2 = find(node_2)

    if root_1 == root_2:
        return False

    if root_1 < root_2:
        parent[root_2] = root_1
    else:
        parent[root_1] = root_2

    return True


def kruskal(e, graph):
    sumWeight = 0
    for s, e, w in graph:
        if union(s, e):
            sumWeight += w
    return sumWeight


if __name__=="__main__":
    V, E = map(int, sys.stdin.readline().split())

    graph = []
    for _ in range(E):
        A, B, C = map(int, sys.stdin.readline().split())
        graph.append((A, B, C))
    graph.sort(key=lambda x: x[2])

    parent = [node for node in range(V + 1)]
    mst_weight = kruskal(E, graph)
    print(mst_weight)
