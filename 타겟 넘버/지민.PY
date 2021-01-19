#깊이/너비 우선 탐색(DFS/BFS)
answer = 0
def dfs(idx, end, total, numbers, target):
    global answer
    #끝까지 탐색했으면
    if idx == end:
        #다 계산한 값이 target값이면
        if total == target:
            answer += 1
            return
    #끝이 아니면 계속
    else:
        dfs(idx+1, len(numbers), total+numbers[idx], numbers, target)     
        dfs(idx+1, len(numbers), total-numbers[idx], numbers, target)
        return


def solution(numbers, target):
    global answer
    end = len(numbers)
    
    dfs(0, end, 0, numbers, target)

    return answer
