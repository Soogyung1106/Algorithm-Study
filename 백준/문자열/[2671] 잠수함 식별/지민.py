import sys
import re


input_func = sys.stdin.readline
if __name__ == '__main__':
    input_string = str(*map(str, input_func().split()))

    regex = re.compile('(100+1+|01)+')
    is_match = regex.fullmatch(input_string)

    if is_match:
        print('SUBMARINE')
    else:
        print('NOISE')
