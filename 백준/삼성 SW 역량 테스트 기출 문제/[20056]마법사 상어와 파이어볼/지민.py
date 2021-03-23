import sys
from collections import defaultdict


if __name__=="__main__":
    N, M, K = map(int, sys.stdin.readline().split())
    #r, c, m, s, d(행, 열, 질량, 속력, 방향)
    fireballs = [list(map(int, sys.stdin.readline().split())) for _ in range(M)]
    fballs = []
    for fire in fireballs:
        r, c, m, s, d = fire
        fballs.append([r-1, c-1, m, s, d])

    direction = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

    for _ in range(K):
        #파이어볼 이동
        map = defaultdict(list)
        for ball in fballs:
            r, c, m, s, d = ball
            ball[0] = (r+direction[d][0]*s)%N
            ball[1] = (c+direction[d][1]*s)%N
            map[ball[0], ball[1]].append([m, s, d])

        #2개 이상의 파이어볼
        fballs = []
        for (x, y), b in map.items():
            if len(b) == 1:
                value = [x, y]
                value.extend(b[0])
                fballs.append(value)
                continue

            #합치기
            #질량, 속력, 방향 카운트
            msum, ssum = 0, 0
            odd_count, even, even_count = 0, False, 0
            for m, s, d in b:
                msum += m
                ssum += s
                if d%2 == 0:
                    even_count += 1
                elif d%2 == 1:
                    odd_count += 1
            #갱신 파이어볼 값 설정
            m = msum//5
            s = ssum//len(b)
            if len(b) in (even_count, odd_count):
                even = True

            #갱신
            if m == 0:
                continue
            for idx in range(4):
                if even:
                    fballs.append([x, y, m, s, idx*2])
                else:
                    fballs.append([x, y, m, s, (idx*2+1)])

    answer = sum(m for r, c, m, s, d in fballs)
    print(answer)
