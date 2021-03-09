import sys
from collections import deque


if __name__=="__main__":
    N, K = map(int, sys.stdin.readline().split())
    A = deque(list(map(int, sys.stdin.readline().split())))

    belt = deque([0]*N)

    count = 1
    while True:
        #1단계_벨트 한칸 회전
        A.rotate(1)
        belt.rotate(1)
        belt[N-1] = 0

        #2단계_로봇 이동
        #먼저 올라간 로봇부터
        for i in range(N-1, -1, -1):
            #벨트에 로봇이 있고, 이동할 수 있으면
            if belt[i] == 1 and belt[i+1] == 0 and A[i+1] > 0:
                belt[i] = 0
                belt[i+1] = 1
                A[i+1] -= 1
        belt[N-1] = 0

        #3단계_새 로봇
        if belt[0] == 0 and A[0] > 0:
            belt[0] = 1
            A[0] -= 1

        if A.count(0) >= K:
            break

        count += 1

    print(count)

