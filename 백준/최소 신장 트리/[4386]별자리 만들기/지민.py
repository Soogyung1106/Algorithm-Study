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


def kruskal(n, graph):
    sumWeight = 0
    for s, e, w in graph:
        if union(s, e):
            sumWeight += w
    return sumWeight


if __name__=="__main__":
    n = int(*map(int, sys.stdin.readline().split()))

    node = []
    for _ in range(n):
        x, y = map(float, sys.stdin.readline().split())
        node.append((x, y))

    graph = []
    for i in range(n):
        for j in range(i+1, n):
            weight = (abs(node[i][0]-node[j][0])**2 + abs(node[i][1]-node[j][1])**2)**(1/2)
            graph.append((i, j, round(weight, 4)))

    graph.sort(key=lambda x: x[2])

    parent = [node for node in range(n + 1)]
    mst_weight = kruskal(n, graph)
    print(round(mst_weight, 2))
