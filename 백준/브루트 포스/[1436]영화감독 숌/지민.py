import sys

if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    start = 666

    for n in range(N-1):
        while True:
            start += 1
            if '666' in str(start):
                break

    print(start)
