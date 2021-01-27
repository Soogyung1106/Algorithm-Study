#2017 팁스타운
def solution(n,a,b):
    answer, cnt = 0, 1
    a, b = min(a, b), max(a, b)
    
    while True:
        #종료조건
        #a가 작은 수니까 홀수칸(앞쪽)에 있고, a랑 b가 붙어있을 때
        if a%2==1 and a+1==b:
            return cnt
        
        #라운드 횟수
        cnt+=1
        #다음 라운드로(몫으로 위치 지정)
        if a%2==1:
            a=a//2+1
        else:
            a=a//2
        
        if b%2==1:
            b=b//2+1
        else:
            b=b//2                 
    
    return answer
