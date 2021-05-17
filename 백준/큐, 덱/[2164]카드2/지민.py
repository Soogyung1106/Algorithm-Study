import sys
from collections import deque


input = sys.stdin.readline
if __name__ == '__main__':
    N = int(*map(int, input().split()))
    cards = deque([idx for idx in range(1, N+1)])

    idx = 0
    while len(cards) != 1:
        if idx%2 == 0:
            _ = cards.popleft()
        else:
            cards.append(cards.popleft())
        idx += 1

    print(cards.popleft())
