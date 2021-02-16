import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    cal = [0]*(N+1)

    for n in range(1, N+1):
        if n == 1:
            continue
        count = []
        #3으로 나누어 떨어지면
        if n % 3 == 0:
            count.append(cal[n//3]+1)
        #2로 나누어 떨어지면
        if n % 2 == 0:
            count.append(cal[n//2]+1)
        #1을 뺀다
        count.append(cal[n-1]+1)

        #가장 적은 연산 횟수로 갱신
        cal[n] = min(count)

    print(cal[N])
