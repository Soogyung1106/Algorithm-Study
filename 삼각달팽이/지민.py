#월간 코드 챌린지 시즌1
def solution(n):
    alnum = int(n*(n+1)/2)
    num = 1
    x, y, course = 0, 0, 0
    #삼각형 모양 배열 선언
    num_arr = [[0 for j in range(i+1)] for i in range(n)]
    num_arr[x][y] = 1
    
    #num 값이 MAX값이 아닐 때 계속 진행(=MAX값이 되면 stop)
    while num != alnum:
        #다음 좌표 설정
        #아랫 방향(course = 0)
        if course % 3 == 0:
            nx = x+1
            ny = y
        #오른쪽(course = 1)
        elif course % 3 == 1:
            nx = x
            ny = y+1
        #윗 방향(course = 2)
        elif course % 3 == 2:
            nx = x-1
            ny = y-1
        
        #좌표 확인 및 내용물 확인
        if 0<=nx<n and 0<=ny<len(num_arr[nx]) and num_arr[nx][ny] == 0:
            num += 1
            num_arr[nx][ny] = num
            x, y = nx, ny
        #좌표가 해당 줄의 좌표가 아니거나 / num_arr 해당좌표에 이미 숫자가 들어갔을 때 방향 전환
        else:
            course += 1

    answer = sum(num_arr, [])
    return answer
