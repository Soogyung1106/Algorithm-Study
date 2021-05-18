import sys
from itertools import combinations


input = sys.stdin.readline
if __name__ == '__main__':
    N, S = map(int, input().split())
    numbers = list(map(int, input().split()))

    number_comb = []
    for n in range(1, N+1):
        number_comb.extend(list(combinations(numbers, n)))

    count = 0
    for comb in number_comb:
        if sum(comb) == S:
            count += 1

    print(count)
