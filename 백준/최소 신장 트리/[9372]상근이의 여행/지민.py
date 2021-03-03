#통과 코드
#N개 국들 간의 가중치가 모두 같고, 비행 스케줄은 항상 연결리스트, 정점을 여러 번 방문해도 된다.
#  => 정점을 모두 잇는 최소한의 간선 갯수는 N-1개가 아닌가?
"""
import sys


if __name__=="__main__":
    T = int(*map(int, sys.stdin.readline().split()))

    for _ in range(T):
        N, M = map(int, sys.stdin.readline().split())

        for _ in range(M):
            a, b = map(int, sys.stdin.readline().split())

        print(N-1)
"""

#bfs 사용
import sys
from collections import deque


def bfs(start, N, graph):
    visited = [0]*N
    visited[start - 1] = 1
    route = deque([start])
    count = 0
    while route:
        n = route.popleft()
        for node in graph[n]:
            if visited[node-1] == 0:
                visited[node-1] = 1
                route.append(node)
                count += 1

    return count


if __name__=="__main__":
    T = int(*map(int, sys.stdin.readline().split()))

    for _ in range(T):
        N, M = map(int, sys.stdin.readline().split())

        #{1: {2: 1, 3: 1}, 2: {1: 1, 3: 1}, 3: {2: 1, 1: 1}}
        airplanes = {}
        for _ in range(M):
            a, b = map(int, sys.stdin.readline().split())
            if a not in airplanes.keys():
                airplanes[a] = {b: 1}
            else:
                airplanes[a][b] = 1

            if b not in airplanes.keys():
                airplanes[b] = {a: 1}
            else:
                airplanes[b][a] = 1

        minCnt = 1e9
        for start in airplanes.keys():
            cnt = bfs(start, N, airplanes)
            minCnt = min(minCnt, cnt)
        print(minCnt)
