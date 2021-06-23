import sys


input_func = sys.stdin.readline
if __name__ == '__main__':
    input_string = str(*map(str, input_func().split()))
    string_length = len(input_string)

    answer = -1
    if input_string != ''.join(list(reversed(input_string))):
        answer = string_length
    elif input_string[1:] != ''.join(list(reversed(input_string[1:]))):
        answer = string_length-1


    print(answer)
