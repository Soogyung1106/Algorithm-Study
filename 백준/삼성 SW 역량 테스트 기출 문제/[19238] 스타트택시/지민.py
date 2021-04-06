import sys
from collections import deque
from collections import defaultdict


#bfs
def calc_distance(start, graph, destination):
    route = deque([start])
    visited = [[-1]*N for _ in range(N)]
    visited[start[0]][start[1]] = 0

    if destination:
        destination_flag = True
    else:
        destination_flag = False

    while route:
        x, y = route.popleft()

        if destination_flag and (x, y) == destination:
            return visited[x][y]

        for idx in range(4):
            nx, ny = x + dx[idx], y + dy[idx]

            if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == -1:
                if graph[nx][ny] == 0:
                    route.append((nx, ny))
                    visited[nx][ny] = visited[x][y] + 1

    return visited


if __name__=="__main__":
    N, M, fuel = map(int, sys.stdin.readline().split())
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
    start_x, start_y = map(int, sys.stdin.readline().split())
    passengers = defaultdict(dict)
    for idx in range(M):
        p_temp = list(map(int, sys.stdin.readline().split()))
        passengers[idx]['start'] = (p_temp[0]-1, p_temp[1]-1)
        passengers[idx]['destination'] = (p_temp[2]-1, p_temp[3]-1)

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    start_x, start_y = start_x-1, start_y-1
    for _ in range(M):
        passenger_distance = calc_distance((start_x, start_y), maps, None)

        passengers_distance_temp = []
        for p_idx, p in passengers.items():
            p_x, p_y = p['start']
            if passenger_distance[p_x][p_y] == -1:
                fuel = -1
                break
            passengers_distance_temp.append((p_idx, p['start'], p['destination'], passenger_distance[p_x][p_y]))

        if fuel < 0:
            break
        
        passengers_distance_temp.sort(key=lambda x: (x[3], x[1][0], x[1][1]))
        min_passenger = passengers_distance_temp[0]

        if min_passenger[3] <= fuel:
            fuel -= min_passenger[3]
        else:
            fuel = -1
            break

        destination_distance = calc_distance(min_passenger[1], maps, min_passenger[2])

        if type(destination_distance) == list:
            fuel = -1
            break
        elif destination_distance <= fuel:
            fuel += destination_distance
            start_x, start_y = min_passenger[2]
            passengers.pop(min_passenger[0])
        else:
            fuel = -1
            break

    print(fuel if not passengers else -1)
