import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    line = []
    dp = [1]*N

    for _ in range(N):
        line.append(list(map(int, sys.stdin.readline().split(' '))))

    line = sorted(line, key=lambda x: x[0])

    #A전봇대에 연결된 전깃줄이 B전봇대에 연결된 전깃줄보다 크면 안겹쳐
    # (1, 2) / (2, 5) => A1 < A2 일 때, B1< B2 이면 안겹침
    for i in range(N):
        for j in range(i):
            #안 겹칠 때
            if line[i][1] > line[j][1]:
                dp[i] = max(dp[i], dp[j]+1)

    print(N-max(dp))
