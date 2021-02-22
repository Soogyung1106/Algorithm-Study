import sys
from itertools import combinations

if __name__=="__main__":
    N, M = map(int, sys.stdin.readline().split(' '))
    card = list(map(int, sys.stdin.readline().split(' ')))
    max_num = 0

    for c in combinations(card, 3):
        num = sum(c)
        if num > M:
            continue

        max_num = max(max_num, num)

    print(max_num)
