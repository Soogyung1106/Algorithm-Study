#깊이/넓이 우선 탐색(DFS/BFS)
def dfs(computer, start):
    visited = []
    node = [start]
    
    while node:
        n = node.pop()
        if n not in visited:
            visited.append(n)
            node += computer[n] - set(visited)
    return visited


def solution(n, computers):
    answer = 0
    graph = {}
    visited = []
    
    #딕셔너리
    for idx in range(0, n):
        nIdx = []
        for node in range(len(computers[idx])):
            if computers[idx][node] == 1:
                nIdx.append(node)
        graph[idx] = set(nIdx)

    #탐색
    idx = 0
    while len(visited) != n:
        if idx not in visited:
            visited.extend(dfs(graph, idx))
            answer += 1
        idx += 1
        
    return answer
