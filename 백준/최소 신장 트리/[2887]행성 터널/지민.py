import sys


def find(node):
    #자기 자신이 루트노드
    if parent[node] == node:
        return node

    parent[node] = find(parent[node])
    return parent[node]


def union(node_u, node_v):
    root_u = find(node_u)
    root_v = find(node_v)

    #사이클 체크
    if root_u == root_v:
        return False

    if root_u < root_v:
        parent[root_v] = root_u
    else:
        parent[root_u] = root_v
    return True


def kruskal(graph):
    sumWeight = 0
    for s, e, w in graph:
        if union(s, e):
            sumWeight += w

    return sumWeight


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))

    node = []
    for idx in range(N):
        x, y, z = map(int, sys.stdin.readline().split())
        node.append((idx, x, y, z))

    graph = []
    #x좌표
    node.sort(key=lambda x: x[1])
    for i in range(N-1):
        #(출발 노드, 도착 노드, 가중치)
        graph.append((node[i][0], node[i+1][0], abs(node[i][1]-node[i+1][1])))
    #y좌표
    node.sort(key=lambda x: x[2])
    for i in range(N-1):
        graph.append((node[i][0], node[i+1][0], abs(node[i][2]-node[i+1][2])))
    #z좌표
    node.sort(key=lambda x: x[3])
    for i in range(N-1):
        graph.append((node[i][0], node[i+1][0], abs(node[i][3]-node[i+1][3])))

    graph.sort(key=lambda x: x[2])

    parent = [node for node in range(N + 1)]
    mst_weight = kruskal(graph)
    print(mst_weight)
