import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    consulting = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    price_dp = [0]*N

    for idx in range(N-1, -1, -1):
        new_day = consulting[idx][0] + idx
        #마지막 날일때
        if idx == N-1:
            if consulting[idx][0] == 1:
                price_dp[idx] = consulting[idx][1]
        #끝나는 날이 마지막 날
        elif new_day == N:
            price_dp[idx] = max(consulting[idx][1], price_dp[idx+1])
        elif new_day < N:
            #새롭게 일을 시작하는 게 나은 지, 이전 일을 받아오는 게 나은지
            price_dp[idx] = max(consulting[idx][1] + price_dp[new_day], price_dp[idx+1])
        #일하는 날
        else:
            price_dp[idx] = price_dp[idx+1]

    print(max(price_dp))
