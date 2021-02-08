#스택/
def solution(priorities, location):
    answer = 0
    prior_list = list(enumerate(priorities, 0))

    while True:
        #해당 순서 일단 뽑아놓기
        num = prior_list.pop(0)
        #뽑아놓은 친구 보다 큰 우선순위가 존재하면(any)
        if any(num[1] < prior[1] for prior in prior_list):
            prior_list.append(num) 
        #뽑아놓은 친구가 제일 크면
        else:
            answer += 1
            if num[0] == location:
                return answer
            
    return answer
