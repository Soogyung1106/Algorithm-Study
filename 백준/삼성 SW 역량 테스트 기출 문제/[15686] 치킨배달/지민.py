import sys
from itertools import combinations


if __name__=="__main__":
    N, M = map(int, sys.stdin.readline().split())
    house, chicken = [], []
    for r in range(N):
        row = list(map(int, sys.stdin.readline().split()))
        for c in range(N):
            if row[c] == 1:
                house.append((r, c))
            elif row[c] == 2:
                chicken.append((r, c))

    chicken_combination = list(combinations(chicken, M))

    #치킨집 M개만 남긴 경우 반복
    answer = sys.maxsize
    for chicken_comb in chicken_combination:
        distance = 0
        #치킨 거리 계산
        for hx, hy in house:
            minDistance = sys.maxsize
            for cx, cy in chicken_comb:
                minDistance = min(minDistance, abs(hx-cx)+abs(hy-cy))
            distance += minDistance
        answer = min(answer, distance)

    print(answer)
