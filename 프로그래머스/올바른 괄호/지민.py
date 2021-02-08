from collections import Counter

def solution(s):
    answer = True
    s_stack = []
    
    count_s = Counter(s)
    if count_s['('] != count_s[')']:
        return False
    else:
        for i in s:
            if i == '(':
                s_stack.append(i)
            #'('가 아니면 ==> ')'이면
            else:
                if len(s_stack) >= 1:
                    s_stack.pop()
                #stack에 값이 없는데 ')'이면
                else:
                    return False
    
    if len(s_stack) != 0: 
        answer = False
    return answer
