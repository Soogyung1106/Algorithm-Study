import sys

if __name__=="__main__":
    K = int(*map(int, sys.stdin.readline().split()))
    stack = []

    for _ in range(K):
        n = int(*map(str, sys.stdin.readline().split()))
        if n == 0:
            stack.pop()
        else:
            stack.append(n)

    if len(stack) == 0:
        print('0')
    else:
        print(sum(stack))
