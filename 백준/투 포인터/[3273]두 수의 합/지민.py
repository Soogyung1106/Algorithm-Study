import sys


input = sys.stdin.readline
if __name__ == '__main__':
    n = int(*map(int, input().split()))
    a = sorted(list(map(int, input().split())))
    x = int(*map(int, input().split()))

    i, j = 0, n-1
    answer = 0
    while i<j:
        calc_num = a[i] + a[j]
        if calc_num == x:
            answer += 1

        if calc_num < x:
            i += 1
            continue

        j -= 1
    print(answer)
