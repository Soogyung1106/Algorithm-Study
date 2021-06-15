import sys
from collections import deque


input_func = sys.stdin.readline
if __name__ == '__main__':
    N = int(*map(int, input_func().split()))
    in_cars = deque([str(*map(str, input_func().split())) for _ in range(N)])
    out_cars = deque([str(*map(str, input_func().split())) for _ in range(N)])

    overtaking, overtaking_count = None, 0
    while in_cars and out_cars:
        in_car = in_cars[0]
        out_car = out_cars.popleft()

        if not overtaking and in_car != out_car:
            overtaking = in_car

        elif not overtaking and in_car == out_car:
            in_cars.popleft()


        if overtaking and out_car != overtaking:
            overtaking_count += 1
            for idx in range(len(in_cars)):
                if out_car == in_cars[idx]:
                    del in_cars[idx]
                    break

        elif overtaking and out_car == overtaking:
            overtaking = None
            in_cars.popleft()
            

    print(overtaking_count)
