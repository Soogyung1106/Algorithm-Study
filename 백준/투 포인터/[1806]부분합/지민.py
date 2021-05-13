import sys


input = sys.stdin.readline
if __name__ == '__main__':
    N, S = map(int, input().split())
    sequence = list(map(int, input().split()))

    i, j, sum_num, min_length = 0, 1, sequence[0], 100001
    while i != N:
        if sum_num >= S:
            min_length = min(min_length, j-i)
            sum_num -= sequence[i]
            i += 1
        else:
            if j != N:
                sum_num += sequence[j]
                j += 1
            else:
                sum_num -= sequence[i]
                i += 1

    print(min_length if min_length != 100001 else 0)
