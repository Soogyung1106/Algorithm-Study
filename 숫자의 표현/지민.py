def solution(n):
    answer = 0
    sum_num = 0
    for i in range(1, n+1):
        sum_num = i
        for j in range(i+1, n+2):
            if sum_num <= n:
                if sum_num == n:
                    answer += 1
                    break
                else:
                    sum_num += j
            else:
                break
    return answer
