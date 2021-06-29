import sys


def find_prime_number():
    _n = int(max_number**0.5)+1
    for n in range(2, _n):
        if prime_number[n]:
            for _idx in range(n+n, max_number+1, n):
                prime_number[_idx] = False


input_func = sys.stdin.readline
if __name__ == '__main__':
    max_number = 100000
    prime_number = [False]*2 + [True]*max_number
    find_prime_number()

    while True:
        input_string = str(*map(str, input_func().split()))
        if input_string == '0':
            break

        max_prime_number, break_flag = 2, False
        for length in range(5, 0, -1):
            for idx in range(len(input_string)-length+1):
                number = input_string[idx:idx+length]
                number = int(''.join(number))
                if 2<=number<=100000 and prime_number[number]:
                    if not break_flag:
                        break_flag=True
                    max_prime_number = max(max_prime_number, number)

            if break_flag:
                break

        print(max_prime_number)
