import sys


def eratos(num):
    numbers = [False, False] + [True]*(num-1)

    primes = []
    for n in range(2, num+1):
        if numbers[n]:
            primes.append(n)
            for sub_n in range(2*n, num+1, n):
                numbers[sub_n] = False

    return primes


input = sys.stdin.readline
if __name__ == '__main__':
    N = int(*map(int, input().split()))
    check_primes = eratos(N)
    primes_length = len(check_primes)

    i, j, sum_num, count = 0, 0, 0, 0
    for i in range(primes_length):
        while sum_num < N and j < primes_length:
            sum_num += check_primes[j]
            j += 1

        if sum_num == N:
            count += 1

        sum_num -= check_primes[i]

    print(count)
