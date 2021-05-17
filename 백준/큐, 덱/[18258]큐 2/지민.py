import sys
from collections import deque


input = sys.stdin.readline
if __name__ == '__main__':
    N = int(*map(int, input().split()))

    queue = deque()
    for _ in range(N):
        cmd = list(map(str, input().split()))

        if cmd[0] == 'push':
            queue.append(cmd[1])

        elif cmd[0] == 'pop':
            try:
                pop_data = queue.popleft()
                print(pop_data)
            except:
                print(-1)

        elif cmd[0] == 'size':
            print(len(queue))

        elif cmd[0] == 'empty':
            print(1 if len(queue) == 0 else 0)

        elif cmd[0] == 'front':
            try:
                print(queue[0])
            except:
                print(-1)

        elif cmd[0] == 'back':
            try:
                print(queue[-1])
            except:
                print(-1)
