import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    K = int(*map(int, sys.stdin.readline().split()))
    apple = [[0]*N for _ in range(N)]
    for _ in range(K):
        x, y = map(int, sys.stdin.readline().split())
        apple[x-1][y-1] = 1
    L = int(*map(int, sys.stdin.readline().split()))
    snake_direction = [list(map(str, sys.stdin.readline().split())) for _ in range(L)]

    route = [[0, 0]]
    apple[0][0] = 2
    count, snake = 0, [[0, 0]]
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    direction = 3
    while route:
        x, y = route.pop()

        nx = x + dx[direction]
        ny = y + dy[direction]

        #벽에 부딪히면
        if 0 > nx or nx >= N or 0 > ny or ny >= N:
            break

        #사과가 있으면
        if apple[nx][ny] == 1:
            apple[nx][ny] = 2
            snake.append([nx, ny])
            route.append([nx, ny])
        #사과가 없으면
        elif apple[nx][ny] == 0:
            apple[nx][ny] = 2
            apple[snake[0][0]][snake[0][1]] = 0
            snake.append([nx, ny])
            del snake[0]
            route.append([nx, ny])
        #내 몸이면
        elif apple[nx][ny] == 2:
            break

        count += 1

        # 방향 전환
        if snake_direction and count == int(snake_direction[0][0]):
            if snake_direction[0][1] == 'L':
                if direction in [2, 3]:
                    direction = abs(direction - 3)
                else:
                    direction = abs(direction + 2)
            elif snake_direction[0][1] == 'D':
                if direction in [0, 1]:
                    direction = abs(direction - 3)
                else:
                    direction = abs(direction - 2)
            del snake_direction[0]
    
    print(count+1)
