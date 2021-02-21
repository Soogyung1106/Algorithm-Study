import sys


if __name__=="__main__":
    n = str(*map(str, sys.stdin.readline().split()))
    minus = n.split('-')

    for m in range(len(minus)):
        sum = 0
        for num in minus[m].split('+'):
            sum += int(num)
        minus[m] = sum

    answer = minus[0]
    for m in range(1, len(minus)):
        answer -= minus[m]

    print(answer)
