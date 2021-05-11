def solution(routes):
    answer = 0
    
    route = sorted(routes, key=lambda x: x[1])
    camera = -30001
    for r_start, r_end in route:
        if r_start > camera:
            answer += 1
            camera = r_end
    
    return answer
