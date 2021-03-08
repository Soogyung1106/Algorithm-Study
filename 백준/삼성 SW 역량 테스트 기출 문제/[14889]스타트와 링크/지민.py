import sys
from itertools import combinations


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    stats = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    players = [idx for idx in range(N)]
    player_comb = list(combinations(players, N//2))

    answer = 1e9
    for start in player_comb:
        link_team = list(set(players) - set(start))
        startStats, linkStats = 0, 0

        #두 명씩 능력치를 확인
        #스타트팀
        start_comb = list(combinations(start, 2))
        for tp1, tp2 in start_comb:
            startStats += (stats[tp1][tp2] + stats[tp2][tp1])
        #링크팀
        link_comb = list(combinations(link_team, 2))
        for op1, op2 in link_comb:
            linkStats += (stats[op1][op2] + stats[op2][op1])

        answer = min(answer, abs(startStats-linkStats))

    print(answer)
