import sys
from collections import deque


def spread_dust(start, graph):
    route = deque(start)
    _dust = [[0]*C for _ in range(R)]
    _dust[aircleaner[0][0]][aircleaner[0][1]] = -1
    _dust[aircleaner[1][0]][aircleaner[1][1]] = -1

    while route:
        x, y = route.popleft()

        count = 0
        for idx in range(4):
            nx = x + dx[idx]
            ny = y + dy[idx]

            if 0<=nx<R and 0<=ny<C:
                if graph[nx][ny] != -1:
                    _dust[nx][ny] += graph[x][y]//5
                    count += 1

        _dust[x][y] += graph[x][y] - ((graph[x][y]//5)*count)

    return _dust


def clean_air(cleaner, graph):
    cleaner_top, cleaner_bottom = cleaner
    _clean = [r[:] for r in graph]
    tx, ty = cleaner_top
    bx, by = cleaner_bottom
    ty, by = ty+1, by+1
    _clean[tx][ty] = 0
    _clean[bx][by] = 0

    top_direction = [3, 0, 2, 1]
    bottom_direction = [3, 1, 2, 0]
    for idx in range(4):
        #공기청정기 상부
        while True:
            ntx = tx + dx[top_direction[idx]]
            nty = ty + dy[top_direction[idx]]

            #제 자리로 돌아옴
            if (ntx, nty) == cleaner_top:
                break

            if 0<=ntx<R and 0<=nty<C:
                _clean[ntx][nty] = graph[tx][ty]
            else:
                break
            tx, ty = ntx, nty

        #공기청정기 하부
        while True:
            nbx = bx + dx[bottom_direction[idx]]
            nby = by + dy[bottom_direction[idx]]

            # 제 자리로 돌아옴
            if (nbx, nby) == cleaner_bottom:
                return _clean

            if 0<=nbx<R and 0<=nby<C:
                _clean[nbx][nby] = graph[bx][by]
            else:
                break
            bx, by = nbx, nby

    return _clean


if __name__=="__main__":
    R, C, T = map(int, sys.stdin.readline().split())
    home, aircleaner = [], []
    for r in range(R):
        home_temp = list(map(int, sys.stdin.readline().split()))
        home.append(home_temp)
        for c in range(C):
            if home_temp[c] == -1:
                aircleaner.append((r, c))

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    clean_home = [r[:] for r in home]
    for _ in range(T):
        #먼지 찾기
        dust = []
        for r in range(R):
            for c in range(C):
                if clean_home[r][c] not in (0, -1):
                    dust.append((r, c))
        diffused_home = spread_dust(dust, clean_home)
        clean_home = clean_air(aircleaner, diffused_home)

    home_dust = sum(clean_home, [])
    print(sum(home_dust)+2)
