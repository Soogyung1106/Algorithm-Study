from collections import deque

def bfs(graph, N, start):
    visited = [0] * (N)
    route = deque([start])
    cnt = -1

    while route:
        c = route.popleft()
        for idx in graph[c]:
            if visited[idx-1] == 0:
                visited[idx-1] = 1
                route += graph[c]
                cnt += 1

    return cnt


if __name__=="__main__":
    N = int(*map(int, input().split()))
    M = int(*map(int, input().split()))
    comDic = {}

    for __ in range(M):
        s, e = map(int, input().split())
        if s in comDic.keys() and e not in comDic[s]:
            comDic[s].append(e)
        else:
            comDic[s] = [e]

        if e in comDic.keys() and s not in comDic[e]:
            comDic[e].append(s)
        else:
            comDic[e] = [s]

    bfsResult = bfs(comDic, N, 1)
    print(bfsResult)
