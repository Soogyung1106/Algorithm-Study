#깊이/너비 우선 탐색(DFS/BFS)
from copy import deepcopy

def dfs(ticket, n, start, visit):
    visited = []
    if len(visit) == n+1:
        return visit
    
    if start not in ticket:
        return
    
    for idx in range(len(ticket[start])):
        ticketD = deepcopy(ticket)
        airport = deepcopy(visit)        
        s = ticketD[start].pop(idx)
        airport.append(s)
        visited = dfs(ticketD, n, s, airport)
        if visited:
            return visited
    return
            

def solution(tickets):
    answer = []
    ticketsDic = {}

    #딕셔너리
    for ticket in sorted(tickets, key=lambda x: x[1]):
        if ticket[0] not in ticketsDic.keys():
            ticketsDic[ticket[0]] = [ticket[1]]
        else:
            ticketsDic[ticket[0]].append(ticket[1])

    answer = dfs(ticketsDic, len(tickets), 'ICN', ['ICN'])
    return answer
