import sys
from collections import deque


input_func = sys.stdin.readline
if __name__ == '__main__':
    N = int(*map(int, input_func().split()))
    waitings, entrance_order = deque(), []
    for _ in range(N):
        waiting_people = list(map(str, input_func().split()))
        temp_waitings = deque()
        for wp in waiting_people:
            space, number = wp.split('-')
            temp_waitings.append((space, int(number)))
        waitings.append(temp_waitings)
        entrance_order.append(list(temp_waitings))

    entrance_order = deque(sorted(sum(entrance_order, [])))

    temp, order, last_person = [], 0, len(entrance_order)
    while entrance_order:

        person = entrance_order[0]

        if waitings and waitings[0] and person == waitings[0][0]:
            entrance_order.popleft()
            waitings[0].popleft()

        elif temp and person == temp[-1]:
            temp.pop()
            entrance_order.popleft()

        else:
            if not waitings:
                break
            temp.append(waitings[0].popleft())

        if waitings and not waitings[0] and N >= 2:
            waitings.popleft()


    if not entrance_order:
        print('GOOD')
    else:
        print('BAD')
