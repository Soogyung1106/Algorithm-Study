import sys


input_func = sys.stdin.readline
if __name__ == '__main__':
    input_string = list(map(str, input_func().rstrip().split(':')))
    ipv6_temp = ['0'*4 for _ in range(8)]

    idx, s_idx, dirc_flag = 0, 0, True
    while True:
        if idx == 8 or (not dirc_flag and input_string[s_idx] == ''):
            break

        if dirc_flag and input_string[s_idx] == '':
            dirc_flag = False
            idx, s_idx = 7, len(input_string)-1

        string_temp = ipv6_temp[idx]+input_string[s_idx]
        ipv6_temp[idx] = string_temp[-4:]
        if dirc_flag:
            idx += 1
            s_idx += 1
        else:
            idx -= 1
            s_idx -= 1

    print(':'.join(ipv6_temp))
