import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    sand = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    r, c = N//2, N//2

    tornado_rotation_time = [i//2+1 for i in range(N*2-1)]
    tornado_direction = [(0, -1), (1, 0), (0, 1), (-1, 0)]
    sand_move_direction = [[(-1, 1, 0.01), (1, 1, 0.01), (-2, 0, 0.02), (2, 0, 0.02), (-1, 0, 0.07), (1, 0, 0.07),
                  (-1, -1, 0.1), (1, -1, 0.1), (0, -2, 0.05), (0, -1, 0.55)],
                 [(-1, -1, 0.01), (-1, 1, 0.01), (0, -2, 0.02), (0, 2, 0.02), (0, -1, 0.07), (0, 1, 0.07),
                  (1, -1, 0.1), (1, 1, 0.1), (2, 0, 0.05), (1, 0, 0.55)],
                 [(-1, -1, 0.01), (1, -1, 0.01), (-2, 0, 0.02), (2, 0, 0.02), (-1, 0, 0.07), (1, 0, 0.07),
                  (-1, 1, 0.1), (1, 1, 0.1), (0, 2, 0.05), (0, 1, 0.55)],
                 [(1, -1, 0.01), (1, 1, 0.01), (0, -2, 0.02), (0, 2, 0.02), (0, -1, 0.07), (0, 1, 0.07),
                  (-1, -1, 0.1), (-1, 1, 0.1), (-2, 0, 0.05), (-1, 0, 0.55)]]
    rotation_time, move_time, direction = 0, 0, 0
    sand_lose = 0
    while (r, c) != (0, 0):

        if move_time == tornado_rotation_time[rotation_time]:
            move_time = 0
            direction += 1
            direction %= 4
            rotation_time += 1

        nr = r + tornado_direction[direction][0]
        nc = c + tornado_direction[direction][1]

        y = sand[nr][nc]
        total_move_sand = 0
        for dx, dy, percentage in sand_move_direction[direction]:
            if percentage == 0.55:
                move_sand = y-total_move_sand
            else:
                move_sand = int(y*percentage)

            move_sand_r, move_sand_c = nr + dx, nc + dy

            if 0<=move_sand_r<N and 0<=move_sand_c<N:
                sand[move_sand_r][move_sand_c] += move_sand
            else:
                sand_lose += move_sand
            total_move_sand += move_sand

        r, c = nr, nc
        move_time += 1

    print(sand_lose)
