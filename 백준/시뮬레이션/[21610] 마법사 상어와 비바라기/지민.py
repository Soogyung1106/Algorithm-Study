import sys

input_func = sys.stdin.readline
if __name__ == '__main__':
    N, M = map(int, input_func().split())
    A = [list(map(int, input_func().split())) for _ in range(N)]

    clouds = [(N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)]

    dx = [0, -1, -1, -1, 0, 1, 1, 1]
    dy = [-1, -1, 0, 1, 1, 1, 0, -1]
    for _ in range(M):
        d, s = map(int, input_func().split())

        move_clouds = []
        for cloud_idx in range(len(clouds)):
            cloud_x, cloud_y = clouds[cloud_idx]
            next_cloud_x = (N + cloud_x + (dx[d-1]*s)) % N
            next_cloud_y = (N + cloud_y + (dy[d-1]*s)) % N

            move_clouds.append((next_cloud_x, next_cloud_y))

        is_cloud = [[False]*N for _ in range(N)]
        for mv_x, mv_y in move_clouds:
            A[mv_x][mv_y] += 1
            is_cloud[mv_x][mv_y] = True

        find_directions = [1, 3, 5, 7]
        for mv_x, mv_y in move_clouds:
            rain_count = 0
            for fd in find_directions:
                find_x, find_y = mv_x+dx[fd], mv_y+dy[fd]
                if not 0<=find_x<N or not 0<=find_y<N:
                    continue

                if A[find_x][find_y] == 0:
                    continue

                rain_count += 1

            A[mv_x][mv_y] += rain_count

        clouds = []
        for i in range(N):
            for j in range(N):
                if A[i][j] <= 1:
                    continue

                if not is_cloud[i][j]:
                    clouds.append((i, j))
                    A[i][j] -= 2

    print(sum(sum(A, [])))
