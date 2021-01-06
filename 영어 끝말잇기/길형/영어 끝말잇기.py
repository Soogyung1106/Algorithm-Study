def solution(n, words):  
    for i in range(1,len(words)):
        if words[i][0] != words[i-1][-1]:
            return [(i%n)+1,int((i/n)+1)]
        for j in range(0,i):
            if words[j] == words[i]:
                return [(i%n)+1,int((i/n)+1)]

    return [0,0]
