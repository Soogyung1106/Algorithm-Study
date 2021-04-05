import sys


def count_ward_population(ward, d1, d2):
    ward_population = [0]*5
    global min_population_difference

    for i in range(x+d1):
        for j in range(y+1):
            if (i, j) in ward:
                break
            ward_population[0] += city[i][j]

    for i in range(x+d2+1):
        for j in range(N-1, y, -1):
            if (i, j) in ward:
                break
            ward_population[1] += city[i][j]

    for i in range(x+d1, N):
        for j in range(y-d1+d2):
            if (i, j) in ward:
                break
            ward_population[2] += city[i][j]

    for i in range(N-1, x+d2, -1):
        for j in range(N-1, y-d1+d2-1, -1):
            if (i, j) in ward:
                break
            ward_population[3] += city[i][j]

    ward_population[4] = total_population - sum(ward_population)

    population_difference = max(ward_population) - min(ward_population)
    min_population_difference = min(min_population_difference, population_difference)


def set_ward_5(start, direction, d1, d2):
    ward_5.append(start)

    if direction == 3 and start[0]+dx[3] == x and start[1]+dy[3] == y:
        count_ward_population(ward_5, d1, d2)
    else:
        nr, nc = start[0] + dx[direction], start[1] + dy[direction]
        if 0<=nr<N and 0<=nc<N:
            if direction == 1:
                d1 += 1
            elif direction == 2:
                d2 += 1

            set_ward_5((nr, nc), direction, d1, d2)

            if direction != 3:
                set_ward_5((nr, nc), direction+1, d1, d2)
    ward_5.pop()


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    city = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
    total_population = sum(sum(city, []))
    ward_5 = []
    min_population_difference = sys.maxsize

    dx = [1, 1, -1, -1]
    dy = [1, -1, -1, 1]
    for r in range(N):
        for c in range(N):
            x, y = r, c
            set_ward_5((r, c), 0, 0, 0)

    print(min_population_difference)
