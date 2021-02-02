from itertools import combinations
import bisect

def newGroup(info):
    _info = [[i, info[i]] for i in range(len(info))]
    infoGroup, infoGroup_temp = [['-', '-', '-', '-'] for i in range(0, 16)], []

    for i in range(0, len(_info)):
        infoGroup_temp.extend([list(k) for k in combinations([j for j in _info[:4]], i)])
    
    for i in range(len(infoGroup_temp)):
        for j in range(len(infoGroup_temp[i])):
            idx = infoGroup_temp[i][j][0]
            infoGroup[i][idx] = infoGroup_temp[i][j][1]
        infoGroup[i] = ''.join(infoGroup[i])
    
    return infoGroup


def solution(info, query):
    answer = []
    #쿼리 데이터 처리
    queryList = [q.replace(" and", "").split(" ") for q in query]
    infoList = [i.split(" ") for i in info]
    searchList, score = [], []
    searchGroup = {}
    
    for info in range(len(infoList)):
        searchList = newGroup(infoList[info])
        score = int(infoList[info][-1])

        for search in searchList:
            if search not in searchGroup.keys():
                searchGroup[search] = [score]
            else:
                searchGroup[search].append(score)
    
    for key in searchGroup.keys():
        searchGroup[key].sort()

    for query in queryList:
        count = 0
        _q = ''.join(query[:4])
        _qscore = int(query[4])
        
        if _q not in searchGroup.keys():
            answer.append(0)
        else:
            count=bisect.bisect_left(searchGroup[_q], _qscore)
            answer.append(len(searchGroup[_q])-count)

    return answer









"""
정확도 100, 효율성 0 => 시간초과
from itertools import combinations
def newGroup(info):
    _info = [[i, info[i]] for i in range(len(info))]
    infoGroup, infoGroup_temp = [['-', '-', '-', '-'] for i in range(0, 16)], []
    searchGroup = {}
    for i in range(0, len(_info)):
        infoGroup_temp.extend([list(k) for k in combinations([j for j in _info[:4]], i)])
        score = info[4]
    
    for i in range(len(infoGroup_temp)):
        for j in range(len(infoGroup_temp[i])):
            idx = infoGroup_temp[i][j][0]
            infoGroup[i][idx] = infoGroup_temp[i][j][1]
        infoGroup[i] = ''.join(infoGroup[i])   
        searchGroup[infoGroup[i]] = int(score)
    return searchGroup

def solution(info, query):
    answer = []
    #쿼리 데이터 처리
    queryList = [q.replace(" and", "").split(" ") for q in query]
    infoList = [i.split(" ") for i in info]
    searchGroup = [{}]
    
    for info in range(len(infoList)):
        searchGroup.append(newGroup(infoList[info]))
    
    for query in queryList:
        count = 0
        q = ''.join(query[:4])
        q_score = int(query[4])
        for search in searchGroup:
            if q in search.keys():
                if search[q] >= q_score:
                    count += 1
            
        answer.append(count)
    return answer
"""
    
    

"""
    #시간초과 코드
def solution(info, query):
    for query in queryList:
        info = infoList.copy()
        for q in range(len(query)):
            if query[q] == '-':
                continue
            
            for i in info:
                if i =='' or query[q] in i:
                    continue                
                else:
                    if query[q].isdigit():
                        if int(query[q]) > int(i[4]):
                            info[info.index(i)] = ''
                    else:
                        info[info.index(i)] = ''
            while '' in info:
                info.remove('')
        answer.append(len(info))
    return answer
"""

