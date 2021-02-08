#2020 KAKAO BLIND RECRUITMENT
def solution(s):
    zip_length = []
    answer = 0
    if len(s) == 1:  #입력 문자열 s가 1글자 일때 1 반환
        return 1
    
    #1-문자열을 차례대로 분할(한 글자씩 증가)
    for i in range(1, len(s)-1):
        count = 1
        zip_s = ''
        temp_s = s[:i]
            
        #2-반복되는 문자열 검사(i씩>글자 수씩 증가)
        for j in range(i, len(s), i):
            #2-temp_s가 반복되면 count++
            #[첫 글자:첫 글자+글자 수]
            if s[j:j+i] == temp_s:
                count += 1
            #2-반복 안될 때
            else:
                #count == 1(반복X)이면 문자만 추가
                if count == 1:
                    zip_s += temp_s
                #count != 1(반복O)이면 횟수+문자 추가
                else:
                    zip_s += (str(count) + temp_s)
                #반복 횟수 초기화
                count = 1
                #비교할 문자열 갱신
                temp_s = s[j:j+i]
        
        #1-분할 후 남은 글자
        if count == 1:
            zip_s += temp_s
        else:
            zip_s += (str(count) + temp_s)
        #1-압축 문자열의 길이 저장
        zip_length.append(len(zip_s))
            
    answer = min(zip_length)
    return answer
