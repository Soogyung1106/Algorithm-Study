import sys


if __name__=="__main__":
    answer = []
    T = int(*map(int, sys.stdin.readline().split()))
    arr = [0] * 101
    arr[1:4] = 1, 1, 1

    for _ in range(T):
        N = int(*map(int, sys.stdin.readline().split()))
        for idx in range(4, N+1):
            arr[idx] = (arr[idx-3]+arr[idx-2])
        answer.append(arr[N])

    print("\n".join(map(str, answer)))
