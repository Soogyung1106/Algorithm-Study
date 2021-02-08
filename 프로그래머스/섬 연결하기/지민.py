#탐욕법(Greedy)
def solution(n, costs):
    answer = 0
    costs = sorted(costs, key=lambda x: x[2])
    #경로 중복 방지
    path = set([costs[0][0]])
    
    while len(path) != n:
        for idx in range(len(costs)):
            #경로에 노드 출발지 도착지가 둘 다 있으면 다음으로 pass
            if costs[idx][0] in path and costs[idx][1] in path:
                continue
            
            #노드 출발/도착지 하나라도 있으면 길 잇기
            if costs[idx][0] in path or costs[idx][1] in path:
                path.update([costs[idx][0], costs[idx][1]])
                answer += costs[idx][2]
                #이미 사용한 노드 데이터 삭제
                costs[idx] = [-1, -1, -1]
                #경로 추가 후 가중치 노드 처음부터 확인 => for문 break
                break

    return answer
