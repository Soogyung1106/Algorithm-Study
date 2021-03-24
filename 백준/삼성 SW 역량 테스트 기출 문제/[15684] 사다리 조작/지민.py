import sys


#사다리 연결 확인
def check_ladder(graph):
    for i in range(N):
        c = i
        for r in range(H):
            #사다리가 연결되어 있으면 오른쪽으로
            if graph[r][c] == 1:
                c += 1
            #사다리가 연결되어 있지 않으면 왼쪽 확인, 왼쪽으로
            elif c>0 and graph[r][c-1] == 1:
                c-=1
        #i번째 사다리가 i번째로 돌아오지 않았을 때
        if i != c:
            return False
    return True


def add_ladder(depth, x, y):
    global answer
    #종료 조건/갱신
    if answer <= depth or depth > 3:
        return
    if check_ladder(board):
        answer = min(answer, depth)
        return

    #사다리 추가
    for r in range(x, H):
        k = y if r == x else 0
        for c in range(k, N-1):
            #연결이 안되어 있을 때
            if board[r][c]!=1 and board[r][c-1]!=1 and board[r][c+1]!=1:
                board[r][c] = 1
                add_ladder(depth+1, r, c+2)
                board[r][c] = 0


if __name__=="__main__":
    N, M, H = map(int, sys.stdin.readline().split())

    #연결된 사다리의 시작점 1로 설정
    board = [[0] * N for _ in range(H)]
    for _ in range(M):
        hx, hy = map(int, sys.stdin.readline().split())
        board[hx-1][hy-1] = 1

    answer = 4
    add_ladder(0, 0, 0)
    print(answer if answer < 4 else -1)
