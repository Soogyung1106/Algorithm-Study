def solution(board):
    answer = 0
    maxnum = 0
    
    for i in range(1, len(board)):
        x = board[i]
        for j in range(1, len(x)):
            if board[i][j] != 0 and board[i-1][j] != 0 and board[i][j-1] != 0 and board[i-1][j-1] != 0:
                board[i][j] = min(board[i-1][j-1], board[i-1][j], board[i][j-1]) + 1
    
    for i in range(len(board)):
        for j in range(len(board[i])):
            if maxnum <= board[i][j]:
                maxnum = board[i][j]
            
    answer = maxnum ** 2
    return answer
