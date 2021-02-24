import sys

if __name__=="__main__":
    T = int(*map(int, sys.stdin.readline().split()))
    stack = []

    for _ in range(T):
        C = list(map(str, sys.stdin.readline().split()))

        command = C[0]
        if command == 'push':
            stack.append(C[1])
        elif command == 'pop':
            if len(stack) == 0:
                print('-1')
            else:
                print(stack.pop())
        elif command == 'size':
            print(len(stack))
        elif command == 'empty':
            if len(stack) == 0:
                print('1')
            else:
                print('0')
        elif command == 'top':
            if len(stack) == 0:
                print('-1')
            else:
                print(stack[-1])
