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


def kruskal(graph):
    sumWeight = 0
    for s, e, w in graph:
        if union(s, e):
            sumWeight += w
    return sumWeight


if __name__=="__main__":
    N, E = map(int, sys.stdin.readline().split())
    parent = [node for node in range(N + 1)]

    node = []
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().split())
        node.append((x, y))

    already = []
    for _ in range(E):
        n1, n2 = map(int, sys.stdin.readline().split())
        union(n1-1, n2-1)

    graph = []
    for i in range(N):
        for j in range(i+1, N):
            weight = (abs(node[i][0]-node[j][0])**2 + abs(node[i][1]-node[j][1])**2)**(1/2)
            graph.append((i, j, round(weight, 4)))

    graph.sort(key=lambda x: x[2])

    mst_weight = kruskal(graph)
    print(format(mst_weight, ".2f"))
