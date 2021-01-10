#스택/
def solution(prices):
    answer = []
    
    for i in range(0, len(prices)):
        count = 0
        for j in range(i, len(prices)-1):
            if prices[i] <= prices[j]:
                count += 1
            else:
                break              
        answer.append(count)    
    return answer
