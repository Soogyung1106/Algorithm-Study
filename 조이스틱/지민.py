#탐욕법(Greedy)
def countChangeAlphabet(alphabet):
    countNumF= ord(alphabet)-ord('A')
    countNumB= ord('Z')-ord(alphabet)+1
    return min(countNumF, countNumB)
    

def solution(name):
    name = list(name)
    init = ['A']*len(name)
    idx = 0
    count = 0
    length = len(name)
    
    
    while True:
        rIdx , lIdx = 1, 1
        #'A'가 아니면 'A'로 바꾼다
        if name[idx] != 'A':
            value = countChangeAlphabet(name[idx])
            count += value
            name[idx] = 'A'

        #name이 'A'로만 되어있으면 break
        if str(name) == str(init):
            break
        #A로만 구성되어 있지 않으면
        else:
            #위치 선정
            for i in range(1, length):
                if name[idx+i] == 'A':
                    rIdx += 1
                else:
                    break
                if name[idx-i] == 'A':
                    lIdx += 1
                else:
                    break
            
            if rIdx > lIdx:
                count += lIdx
                idx -= lIdx
            else:
                count += rIdx
                idx += rIdx
    
    
    answer = count
    return answer
