import sys


def fibonacci(n):
    global numbers

    #이미 계산된 값
    if numbers[n] != 0:
        return numbers[n]

    if n < 2:
        return n
    else:
        numbers[n] = fibonacci(n-1) + fibonacci(n-2)
        return numbers[n]


if __name__=="__main__":
    T = int(*map(int, sys.stdin.readline().split()))
    answer = []
    numbers = [0] * 41
    numbers[0], numbers[1] = 0, 1

    for _ in range(T):
        num = int(*map(int, sys.stdin.readline().split()))
        if num == 0:
            answer.append([1, 0])
        elif num == 1:
            answer.append([0, 1])
        else:
            # 0, 1, 1, 2, 3, 5, 8, 13,...
            # num == 2 > 0:1, 1:1 >> numbers[1], numbers[2]
            # num == 3 > 0:1, 1:2 >> numbers[2], numbers[3]
            answer.append([fibonacci(num-1), fibonacci(num)])

    for ans in answer:
        print(' '.join(map(str, ans)))

