import sys


def floydWarshall(n, graph):
    for via in range(n):
        for start in range(n):
            for end in range(n):
                graph[start][end] = min(graph[start][end], graph[start][via]+graph[via][end])

    return graph


if __name__=="__main__":
    V, E = map(int, sys.stdin.readline().split())

    graph = [[float(1e9)]*V for _ in range(V)]
    for _ in range(E):
        a, b, c = map(int, sys.stdin.readline().split())
        graph[a-1][b-1] = min(graph[a-1][b-1], c)

    minRoute = floydWarshall(V, graph)

    minSum = float(1e9)
    for idx in range(V):
        #제자리로 돌아와야 함 ==> (출발지 >  출발지)
        minSum = min(minSum, minRoute[idx][idx])
    
    if minSum == float(1e9):
        print('-1')
    else:
        print(minSum)
