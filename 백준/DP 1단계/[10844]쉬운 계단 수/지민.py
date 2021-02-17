import sys


def stairNumber(n, num):
    global arr
    if n == 0:
        return arr[0][num]
    if arr[n][num] != 0:
        return arr[n][num]

    #num-1 불가능
    if num == 0:
        arr[n][0] = stairNumber(n-1, 1)
        return arr[n][0]
    elif 1 <= num <= 8:
        arr[n][num] = stairNumber(n-1, num-1) + stairNumber(n-1, num+1)
        return arr[n][num]
    #num+1 불가능
    elif num == 9:
        arr[n][9] = stairNumber(n-1, 8)
        return arr[n][9]


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    arr = [[0]*10 for _ in range(N)]
    arr[0] = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    sum = 0

    for i in range(10):
        sum += stairNumber(N-1, i)

    print(sum%1000000000)
