import sys


def w(a, b, c):
    global arr
    if arr[a][b][c] != '':
        return arr[a][b][c]

    if a <= 0 or b <= 0 or c <= 0:
        return 1
    elif a > 20 or b > 20 or c > 20:
        return w(20, 20, 20)
    elif a < b and b < c:
        num = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
        arr[a][b][c] = num
        return num
    else:
        num = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
        arr[a][b][c] = num
        return num


if __name__=="__main__":
    answer = []
    arr = [[[''] * 51 for _ in range(51)] for _ in range(51)]
    arr[0][0][0] = 1

    while True:
        a, b, c = map(int, sys.stdin.readline().split(" "))
        if a == -1 and b == -1 and c == -1:
            break
        else:
            if a <= 0 or b <= 0 or c <= 0:
                answer.append([a, b, c, 1])
            elif a > 20 or b > 20 or c > 20:
                w(20, 20, 20)
                answer.append([a, b, c, arr[20][20][20]])
            else:
                w(a, b, c)
                answer.append([a, b, c, arr[a][b][c]])

    result = "w({0}, {1}, {2}) = {3}"
    for ans in answer:
        print(result.format(ans[0], ans[1], ans[2], ans[3]))

