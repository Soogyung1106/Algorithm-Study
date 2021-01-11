#스택/큐
def solution(prices):
    answer = []
    
    for i in range(0, len(prices)):
        count = 0
        for j in range(i+1, len(prices)):
            if prices[i] <= prices[j]:
                count += 1
            else:
                count += 1
                break 
        answer.append(count)    
    return answer
