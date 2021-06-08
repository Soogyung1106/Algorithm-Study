import sys
import re


input_func = sys.stdin.readline
if __name__ == '__main__':
    T = int(*map(int, input_func().split()))

    for _ in range(T):
        input_string = str(*map(str, input_func().split()))

        regex = re.compile('(100+1+|01)+')
        is_match = regex.fullmatch(input_string)

        if is_match:
            print('YES')
        else:
            print('NO')
