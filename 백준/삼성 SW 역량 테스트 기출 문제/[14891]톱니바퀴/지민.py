import sys
from collections import deque


def rotate_L(num, direction, graph):
    #제일 앞 톱니바퀴면 왼쪽에 없어
    if num == 0:
        return
    #내 6번이랑 왼쪽 2번이랑 비교
    if graph[num][6] != graph[num-1][2]:
        rotate_L(num-1, -direction, graph)
        graph[num-1].rotate(direction)
    else:
        return


def rotate_R(num, direction, graph):
    #제일 마지막 톱니바퀴이면 오른쪽 없어
    if num == 3:
        return
    #내 2번이랑 오른쪽 6번이랑 비교
    if graph[num][2] != graph[num+1][6]:
        rotate_R(num+1, -direction, graph)
        graph[num+1].rotate(direction)
    else:
        return


if __name__=="__main__":
    #[deque([1, 0, 1, 0, 1, 1, 1, 1]), deque([0, 1, 1, 1, 1, 1, 0, 1]), deque([1, 1, 0, 0, 1, 1, 1, 0]), deque([0, 0, 0, 0, 0, 0, 1, 0])]
    gear = []
    for _ in range(4):
        g = str(*map(str, sys.stdin.readline().split()))
        l = []
        for d in g:
            l.append(int(d))
        gear.append(deque(l))

    K = int(*map(int, sys.stdin.readline().split()))

    for _ in range(K):
        g_num, direction = map(int, sys.stdin.readline().split())
        #rotate 함수 > 음수면 왼쪽, 양수면 오른쪽 회전
        rotate_L(g_num-1, -direction, gear)
        rotate_R(g_num-1, -direction, gear)
        gear[g_num-1].rotate(direction)

    score = 0
    for idx in range(4):
        score += (2**idx) * gear[idx][0]
    print(score)
