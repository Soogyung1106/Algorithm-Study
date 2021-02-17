import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    A = list(map(int, sys.stdin.readline().split(' ')))
    subsequence = [[] for _ in range(N)]
    subsequence[0] = [A[0]]

    for i in range(1, N):
        num = A[i]
        #수열 검사
        for j in range(i):
            if subsequence[j][-1] < num:
                #앞에 더 긴 증가 부분 수열이 있으면 그 친구를 붙여줘야지
                if len(subsequence[i]) -1 < len(subsequence[j]):
                    subsequence[i] = subsequence[j] + [num]

        #검사 돌렸는데 내가 최소값이야
        if not subsequence[i]:
            subsequence[i].append(num)

    answer = 0
    for sub in subsequence:
        if answer < len(sub):
            answer = len(sub)
    print(answer)



