import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    A = list(map(int, sys.stdin.readline().split(' ')))
    subsequence = [0]*N
    subsequence[0] = 1

    #증가하는 부분 수열
    for i in range(1, N):
        num = A[i]
        #수열 검사
        for j in range(i):
            if A[j] < num:
                subsequence[i] = max(subsequence[i], subsequence[j]+1)

        #검사 돌렸는데 내가 최소값이야
        if not subsequence[i]:
            subsequence[i] = 1

    rA = list(reversed(A))
    rsubsequence = [0]*N
    rsubsequence[0] = 1

    #뒤집힌 수열의 증가하는 부분 수열 >> 다시 뒤집어서 붙이면 된다
    for i in range(1, N):
        num = rA[i]
        for j in range(i):
            if rA[j] < num:
                rsubsequence[i] = max(rsubsequence[i], rsubsequence[j] + 1)

        if not rsubsequence[i]:
            rsubsequence[i] = 1

    sum = [s+r-1 for s, r in zip(subsequence, rsubsequence[::-1])]
    print(max(sum))




