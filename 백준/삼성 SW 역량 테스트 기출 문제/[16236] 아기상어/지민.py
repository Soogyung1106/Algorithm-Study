import sys
from collections import deque


def find_fish(start, size, graph):
    route = deque([start])
    visited = [[0]*N for _ in range(N)]
    visited[start[0]][start[1]] = 1
    fish_list = []
    fish_flag = False

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    while route:
        x, y, d = route.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<=nx<N and 0<=ny<N:
                #못 지나가
                if graph[nx][ny] > size:
                    continue
                #물고기가 없어! / 나랑 크기가 같아
                elif (graph[nx][ny] == 0 or graph[nx][ny] == size) and visited[nx][ny] == 0:
                    route.append([nx, ny, d+1])
                    visited[nx][ny] = 1
                #먹을 물고기가 있다
                elif graph[nx][ny] < size and visited[nx][ny] == 0:
                    fish_list.append((nx, ny, d+1))
                    visited[nx][ny] = 1
                    fish_flag = True


    return fish_flag, fish_list


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    space = []
    for r in range(N):
        temp = list(map(int, sys.stdin.readline().split()))
        space.append(temp)
        for c in range(N):
            if temp[c] == 9:
                start = [r, c, 0]
                space[r][c] = 2

    count, fish_count, size = 0, 0, 2
    while True:
        flag, fish_result = find_fish(start, size, space)
        if flag:
            #먹을 수 있는 물고기 정렬 > 가까운 위치 / 행 / 열
            fish_result = sorted(fish_result, key=lambda x: (x[2], x[0], x[1]))
            fish = fish_result[0]
            count += fish[2]
            fish_count += 1
            if fish_count == size:
                fish_count = 0
                size += 1
            space[start[0]][start[1]] = 0
            space[fish[0]][fish[1]] = size
            start = [fish[0], fish[1], 0]
        #엄마
        else:
            break

    print(count)
