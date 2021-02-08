#탐욕법(Greedy)
def solution(people, limit):
    answer = 0
    people.sort()
    #사람 수
    i = 0               #건넌 사람
    j = len(people)-1   #섬 사람(index)

    while i<=j:
        #구명보트 갯수
        answer += 1

        #구명보트에 탈 사람(제일 가벼운 사람), 제일 무거운 사람 비교
        if people[i] + people[j] <= limit:
            #보트에 태우고, 다음 사람으로
            i += 1
        
        #맨 뒷 사람
        j-=1
    
    return answer
