import sys


if __name__=="__main__":
    A = list(str(*map(str, sys.stdin.readline().split())))
    B = list(str(*map(str, sys.stdin.readline().split())))
    nA, nB = len(A), len(B)
    subsequence = [[0]*(nB+1) for _ in range(nA+1)]

    for i in range(nA):
        for j in range(nB):
            if A[i] == B[j]:
                subsequence[i+1][j+1] = subsequence[i][j]+1
            else:
                subsequence[i+1][j+1] = max(subsequence[i][j+1], subsequence[i+1][j])

    print(subsequence[nA][nB])
