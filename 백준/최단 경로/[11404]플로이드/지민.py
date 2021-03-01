import sys


def floydWarshall(n, graph):
    for via in range(n):
        #출발지 > 출발지 초기 값 세팅
        graph[via][via] = 0
        for start in range(n):
            for end in range(n):
                graph[start][end] = min(graph[start][end], graph[start][via]+graph[via][end])

    return graph


if __name__=="__main__":
    n = int(*map(int, sys.stdin.readline().split()))
    m = int(*map(int, sys.stdin.readline().split()))

    graph = [[float(1e9)]*n for _ in range(n)]
    for _ in range(m):
        a, b, d = map(int, sys.stdin.readline().split())
        graph[a-1][b-1] = min(graph[a-1][b-1], d)

    minRoute = floydWarshall(n, graph)
    for s in minRoute:
        for e in range(n):
            if s[e] == float(1e9):
                s[e] = 0        
        print(' '.join(map(str, s)))
