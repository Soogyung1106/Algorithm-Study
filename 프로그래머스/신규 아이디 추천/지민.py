#2021 KAKAO BLIND RECRUITMENT
import re

def solution(new_id):
    answer = ''
    #소문자
    _id = new_id.lower()
    #정규표현식으로 -,_,.를 제외한 특수문자 제거
    _id = re.sub('[~!@#$%^&*\(\)=+\[\{\]\}:?,<>/]', '', _id)
    #정규표현식으로 연속된 . 치환
    _id = re.sub('[\.]{2,}', '.', _id)
    #첫글자/마지막 글자 . 처리
    _id = re.sub('^\.|\.$', '', _id)
    #비어있으면 처리
    if not _id:
        _id = 'a'
    if len(_id) <3:
        _id += _id[-1]*(3-len(_id))
    elif len(_id) >15:
        _id = re.sub('\.$', '', _id[:15])
    
    answer = _id
        
    return answer
