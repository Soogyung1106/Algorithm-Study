import sys


input_func = sys.stdin.readline
if __name__ == '__main__':
    input_string_one = str(*map(str, input_func().split()))
    input_string_two = str(*map(str, input_func().split()))

    string_compare = [[[0, ''] for _ in range(len(input_string_two)+1)] for _ in range(len(input_string_one)+1)]
    for one in range(1, len(input_string_one)+1):
        for two in range(1, len(input_string_two)+1):
            if input_string_one[one-1] == input_string_two[two-1]:
                string_compare[one][two][0] = string_compare[one-1][two-1][0] + 1
                string_compare[one][two][1] = string_compare[one-1][two-1][1] + input_string_one[one-1]
            else:
                if string_compare[one-1][two][0] >= string_compare[one][two-1][0]:
                    string_compare[one][two] = string_compare[one-1][two]
                else:
                    string_compare[one][two] = string_compare[one][two-1]


    print(string_compare[-1][-1][0])
    print(string_compare[-1][-1][1])
