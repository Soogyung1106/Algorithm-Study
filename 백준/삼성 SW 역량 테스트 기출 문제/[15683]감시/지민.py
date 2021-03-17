import sys


def count_blind(start, graph):
    global minCount
    if start == cctv_cnt:
        count_cctv = sum(graph, [])
        minCount = min(minCount, count_cctv.count(0))
        return

    x, y, d = cctvs[start]
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1 ,1]
    #현재 CCTV의 방향 만큼
    for dir in cctv_direction[d]:
        graph_temp = [r[:] for r in graph]
        for idx in dir:
            nx = x + dx[idx]
            ny = y + dy[idx]
            # 끝까지
            while 0 <= nx < N and 0 <= ny < M:
                if graph_temp[nx][ny] == 6:
                    break
                elif graph_temp[nx][ny] == 0:
                    graph_temp[nx][ny] = '#'
                # 다음 칸
                nx += dx[idx]
                ny += dy[idx]
        count_blind(start+1, graph_temp)


if __name__=="__main__":
    N, M = map(int, sys.stdin.readline().split())
    office, cctvs, cctv_cnt = [], [], 0
    for r in range(N):
        temp = list(map(int, sys.stdin.readline().split()))
        office.append(temp)
        for c in range(M):
            if temp[c] not in (0, 6):
                cctvs.append([r, c, temp[c]])
                cctv_cnt += 1

    cctv_direction = [0,
                      [[0], [1], [2], [3]],
                      [[0, 1], [2, 3]],
                      [[0, 3], [3, 1], [1, 2], [2, 0]],
                      [[0, 2, 3], [0, 3, 1], [2, 3, 1], [0, 1, 2]],
                      [[0, 1, 2, 3]]]

    minCount = sys.maxsize
    count_blind(0, office)
    print(minCount)
