import sys


input_func = sys.stdin.readline
if __name__ == '__main__':
    S = str(*map(str, input_func().split()))
    T = str(*map(str, input_func().split()))

    temp_string = T
    while len(S) != len(temp_string):
        if temp_string[-1] == 'A':
            temp_string = temp_string[:-1]
        elif temp_string[-1] == 'B':
            temp_string = temp_string[:-1]
            temp_string = temp_string[::-1]

    print('1' if temp_string == S else '0')
