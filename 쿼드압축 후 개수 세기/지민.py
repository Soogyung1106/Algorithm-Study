#월간 코드 챌린지 시즌1
def solution(arr):
    answer = [0, 0]
    
    def Quard(arr, idxR, idxC, length):
        arr_temp = []
        arrSum = 0
        
        #영역 합 구하기
        for i in range(idxR, idxR+length):
            for j in range(idxC, idxC+length):
                arrSum += arr[i][j]
        
        #영역 내부 합이 전체 크기와 같으면 1 하나 추가
        #영역 내부 합이 0이면 0하나 추가
        if arrSum == 0:
            answer[0] += 1
        elif arrSum == length**2:
            answer[1] += 1
        #영역 내부 합이 전체 크기와 같지 않거나 0이 아닐때
        else:
            #두 개짜리 넘어오면 나눌 거 없응께 처리
            if length == 2:
                answer[0] += (length**2-arrSum)
                answer[1] += arrSum
            #영역 쪼깨기
            else:
                Quard(arr, idxR, idxC, length//2)
                Quard(arr, idxR+(length//2), idxC, length//2)
                Quard(arr, idxR, idxC+(length//2), length//2)
                Quard(arr, idxR+(length//2), idxC+(length//2), length//2)
        
    Quard(arr, 0, 0, len(arr))
    return answer
