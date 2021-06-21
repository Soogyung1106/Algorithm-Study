import sys
from itertools import combinations


input_func = sys.stdin.readline
if __name__ == '__main__':
    input_string = list(*map(str, input_func().split()))

    temp, idx_parenthesis = [], []
    for idx, s in enumerate(input_string):
        if s == '(':
            input_string[idx] = ''
            temp += [idx]
        elif s == ')':
            input_string[idx] = ''
            idx_parenthesis += [(temp.pop(), idx)]

    result = set()
    for num in range(len(idx_parenthesis)):
        for idx in combinations(idx_parenthesis, num):
            sample = input_string[:]
            for i, j in idx:
                sample[i] = '('
                sample[j] = ')'
            result.add(''.join(sample))

    for answer in sorted(result):
        print(answer)
