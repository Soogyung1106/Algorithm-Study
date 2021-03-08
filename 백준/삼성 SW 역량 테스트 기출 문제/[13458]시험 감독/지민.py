import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    student = [A for A in list(map(int, sys.stdin.readline().split()))]
    B, C = map(int, sys.stdin.readline().split())

    #학생 수
    count = 0
    for num in student:
        #총감독관
        num -= B
        count += 1
        if num <= 0 :
            continue
        #부감독관
        else:
            if num%C == 0:
                count += num//C
            else:
                count += (num//C + 1)

    print(count)
