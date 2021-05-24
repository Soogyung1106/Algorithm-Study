import sys
from collections import defaultdict


input_func = sys.stdin.readline
if __name__ == '__main__':
    A, B = map(int, input_func().split())
    N, M = map(int, input_func().split())

    robots = defaultdict(tuple)
    directions = {'N': 0, 'W': 1, 'E': 3, 'S': 2}
    for idx in range(N):
        x, y, d = map(str, input_func().split())
        robots[idx+1] = (B-int(y), int(x)-1, directions[d])
    
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]
    flag = False
    for idx in range(M):
        id, cmd, num = map(str, input_func().split())
        id, num = int(id), int(num)
        robot_x, robot_y, robot_d = robots.pop(id)

        if cmd == 'L':
            num %= 4
            robot_d = (robot_d+(1*num))%4
        elif cmd == 'R':
            num %= 4
            robot_d = (robot_d+(3*num))%4
        elif cmd == 'F':
            for n in range(num):
                robot_x += dx[robot_d]
                robot_y += dy[robot_d]

                if not 0<=robot_x<B or not 0<=robot_y<A:
                    print('Robot {} crashes into the wall'.format(id))
                    flag = True
                    break
                if flag:
                    break

                for key, value in robots.items():
                    compare_x, compare_y, _ = value
                    if robot_x == compare_x and robot_y == compare_y:
                        print('Robot {} crashes into robot {}'.format(id, key))
                        flag = True
                        break
                if flag:
                    break

        if flag:
            break

        robots[id] = (robot_x, robot_y, robot_d)

    if not flag:
        print('OK')
