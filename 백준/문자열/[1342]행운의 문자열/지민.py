import sys
from collections import Counter


def make_lucky_string(length, idx):
    global count

    if length == 0:
        count += 1
        return

    for alphabet, num in string_count.items():
        if num > 0 and alphabet != idx:
            string_count[alphabet] -= 1
            make_lucky_string(length-1, alphabet)
            string_count[alphabet] += 1


input_func = sys.stdin.readline
if __name__ == '__main__':
    input_string = str(*map(str, input_func().split()))
    string_count = dict(Counter(input_string))

    count = 0
    make_lucky_string(len(input_string), string_count[list(string_count.keys())[0]])

    print(count)
