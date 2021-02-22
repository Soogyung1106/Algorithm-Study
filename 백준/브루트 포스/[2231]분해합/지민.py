import sys

if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    answer = 0

    for n in range(N):
        n_separate = list(map(int, str(n)))

        if N == (n + sum(n_separate)):
            answer = n
            break

    print(answer)
