import sys
from collections import deque


input = sys.stdin.readline
if __name__ == '__main__':
    T = int(*map(int, input().split()))

    for _ in range(T):
        p = str(*map(str, input().split()))
        n = int(*map(int, input().split()))
        arr = input().strip('[]\n')

        try:
            arr = deque(map(int, arr.split(',')))
        except:
            arr  = deque()

        forward_direction = True
        error_flag = False
        for cmd in p:
            if cmd == 'R':
                forward_direction = False if forward_direction else True
            elif cmd == 'D':
                try:
                    if forward_direction:
                        _ = arr.popleft()
                    else:
                        _ = arr.pop()
                except:
                    error_flag = True

        if error_flag:
            print('error')
        elif forward_direction:
            print_arr = str(list(arr)).replace(' ', '')
            print(print_arr)
        else:
            print_arr = str(list(reversed(arr))).replace(' ', '')
            print(print_arr)
