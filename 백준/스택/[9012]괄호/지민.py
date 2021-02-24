import sys

if __name__=="__main__":
    T = int(*map(int, sys.stdin.readline().split()))
    stack = []

    for _ in range(T):
        ps = str(*map(str, sys.stdin.readline().split()))

        count = 0
        for s in ps:
            if s == '(':
                count += 1
            else:
                count -= 1

            if count < 0:
                break
        #VPS 일 때
        if count == 0:
            print('YES')
        #아닐 때
        else:
            print('NO')
