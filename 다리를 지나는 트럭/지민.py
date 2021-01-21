#스택/
def solution(bridge_length, weight, truck_weights):
    answer = 0
    idx = 0
    time = 0
    totalWeight = 0
    bridge_stack = []

    passTruck = []
    length = len(truck_weights)
    
    while len(passTruck) != length :
        time += 1
        
        #다리에 트럭이 있고, / 다리의 끝에 트럭이 왔으면
        if bridge_stack and time-bridge_stack[0][0] == bridge_length:
            #다리 끝 트럭을 뽑아서
            t, w = bridge_stack.pop(0)
            passTruck.append(t)
            #현재 다리의 무게에서 빼준다
            totalWeight -= w
        
        #대기 트럭이 있고, / 다리에 트럭이 새로 출발할 수 있을 때
        if truck_weights and totalWeight + truck_weights[0] <= weight:
            #출발할 트럭
            truck = truck_weights.pop(0)
            bridge_stack.append([time, truck])
            totalWeight += truck

    
    answer = time    
    return answer
