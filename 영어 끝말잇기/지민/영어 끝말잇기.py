#Summer/Winter Coding(~2018) 

def solution(n, words):
    answer = []
    for i in range(1, len(words)):
        if words[i-1][-1] != words[i][0] or words[i] in words[:i] or len(words[i]) == 1:
            answer = [(i%n)+1, (i//n)+1]
            break
    if len(answer) == 0: answer = [0, 0]
    return answer
