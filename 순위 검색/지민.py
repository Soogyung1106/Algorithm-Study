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


