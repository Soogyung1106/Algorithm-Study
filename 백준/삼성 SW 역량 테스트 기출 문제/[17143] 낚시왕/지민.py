import sys
from collections import defaultdict


if __name__ == '__main__':
    R, C, M = map(int, sys.stdin.readline().split())
    sharks = defaultdict(dict)
    for _ in range(M):
        r, c, s, d, z = map(int, sys.stdin.readline().split())
        if d in (1, 2):
            s %= (R-1)*2
        else:
            s %= (C-1)*2
        sharks[(r-1, c-1)] = {'size': z, 'speed': s, 'd': d-1}

    fishing_king = -1
    fishing_sharks = 0
    directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
    for _ in range(C):
        fishing_king += 1

        for location, value in sorted(sharks.items()):
            r, c = location
            size, speed, dirc = value.values()
            if c == fishing_king:
                sharks.pop((r, c))
                fishing_sharks += size
                break

        move_sharks = defaultdict(dict)
        for (r, c), value in sorted(sharks.items(), key=lambda x: x[1]['size']):
            size, speed, dirc = value.values()
            dr = r + directions[dirc][0]*speed
            dc = c + directions[dirc][1]*speed
            if 0 <= dr < R and 0 <= dc < C:
                pass
            else:
                dr, dc = r, c
                for _ in range(speed):
                    dr += directions[dirc][0]
                    dc += directions[dirc][1]
                    if dr < 0 or dr >= R:
                        dr -= (directions[dirc][0]*2)
                        dirc = 1 if dirc == 0 else 0

                    if dc < 0 or dc >= C:
                        dc -= (directions[dirc][1]*2)
                        dirc = 2 if dirc == 3 else 3

            move_sharks[(dr, dc)] = {'size': size, 'speed': speed, 'd': dirc}

        sharks = move_sharks

    print(fishing_sharks)
