import sys


def tetromino_cal(x, y):
    maxSum = 0
    for t in tetromino:
        sum = 0
        for idx in range(4):
            try:
                nx = x + t[idx][0]
                ny = y + t[idx][1]
                sum += paper[nx][ny]
            except IndexError:
                continue
        maxSum = max(maxSum, sum)
    return maxSum


if __name__=="__main__":
    N, M = map(int, sys.stdin.readline().split())
    paper = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    tetromino = [[(0, 0), (0, 1), (0, 2), (0, 3)],    #ㅡ
                 [(0, 0), (1, 0), (2, 0), (3, 0)],
                 [(0, 0), (0, 1), (1, 0), (1, 1)],    #ㅁ
                 [(0, 0), (1, 0), (2, 0), (2, 1)],    #L
                 [(0, 1), (1, 1), (2, 1), (2, 0)],
                 [(1, 0), (1, 1), (1, 2), (0, 2)],
                 [(0, 0), (0, 1), (1, 1), (2, 1)],
                 [(0, 0), (1, 0), (1, 1), (1, 2)],
                 [(1, 0), (0, 0), (0, 1), (0, 2)],
                 [(0, 0), (0, 1), (0, 2), (1, 2)],
                 [(2, 0), (1, 0), (0, 0), (0, 1)],
                 [(0, 0), (1, 0), (1, 1), (2, 1)],    #N
                 [(0, 1), (1, 1), (1, 0), (2, 0)],
                 [(0, 1), (0, 2), (1, 1), (1, 0)],
                 [(0, 0), (0, 1), (1, 1), (1, 2)],
                 [(0, 0), (0, 1), (0, 2), (1, 1)],    #ㅜ
                 [(1, 0), (1, 1), (1, 2), (0, 1)],
                 [(0, 0), (1, 0), (2, 0), (1, 1)],
                 [(1, 0), (0, 1), (1, 1), (2, 1)]]

    answer = 0
    for r in range(N):
        for c in range(M):
            answer = max(answer, tetromino_cal(r, c))

    print(answer)
