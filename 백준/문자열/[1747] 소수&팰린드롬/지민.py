import sys


def check_prime(num):

    m = int(num**0.5)
    for n in range(2, m+1):
        if eratos[n]:
            for idx in range(n+n, num+1, n):
                eratos[idx] = False

    return eratos[num]


input_func = sys.stdin.readline
if __name__ == '__main__':
    N = int(*map(int, input_func().split()))

    eratos = ([False] * 2) + ([True] * (1003002))
    check_prime(1003002)

    number = N
    while True:
        if str(number) == str(number)[::-1]:
            if eratos[number]:
                break

        number += 1

    print(number)
