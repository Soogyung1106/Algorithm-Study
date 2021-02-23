import sys

if __name__=="__main__":
    N, M = map(int, sys.stdin.readline().split())
    chess = [str(*map(str, sys.stdin.readline().split())) for _ in range(N)]
    collect = [['']*8 for _ in range(8)]
    answer = []

    for i in range(0, 8, 2):
        collect[i] = 'BWBWBWBW'
        collect[i+1] = 'WBWBWBWB'

    #8칸 씩
    for i in range(N-7):
        for j in range(M-7):
            count = 0
            #검사
            for k in range(8):
                for l in range(8):
                    if chess[i+k][j+l] != collect[k][l]:
                        count += 1
            
            # 반대로 칠된 체스판일 경우에는 거꾸로니까 64-갯수
            answer.append(min(count, 64-count))
    
    print(min(answer))
