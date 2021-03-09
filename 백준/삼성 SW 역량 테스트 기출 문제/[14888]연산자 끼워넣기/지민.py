#dfs로 풀어보기
import sys
from itertools import permutations


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    num = list(map(int, sys.stdin.readline().split()))
    operator_num = list(map(int, sys.stdin.readline().split()))
    operator_sample = ["+", "-", "*", "/"]

    operator = []
    for n, o in zip(operator_num, operator_sample):
        operator.extend(n*o)

    operator_comb = list(permutations(operator, N-1))

    minCal, maxCal = sys.maxsize, -sys.maxsize
    for o_set in operator_comb:
        cal = num[0]
        for idx in range(len(o_set)):
            if o_set[idx] == '+':
                cal = cal + num[idx + 1]
            elif o_set[idx] == '-':
                cal = cal - num[idx + 1]
            elif o_set[idx] == '*':
                cal = cal * num[idx + 1]
            elif o_set[idx] == '/':
                if cal > 0:
                    cal = cal // num[idx + 1]
                else:
                    cal = (-1)*(abs(cal) // num[idx+1])

        minCal = min(minCal, cal)
        maxCal = max(maxCal, cal)

    print(maxCal)
    print(minCal)
