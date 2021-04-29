from collections import defaultdict

def solution(msg):
    answer = []
    
    zip_dict, n = defaultdict(str), 1
    for a in range(65, 91):
        zip_dict[chr(a)] = n
        n += 1
    
    _msg = msg
    while _msg:
        idx = 1
        while _msg[:idx] in zip_dict.keys() and idx <= len(_msg):
            idx += 1
        
        idx -= 1
        answer.append(zip_dict[_msg[:idx]])
        zip_dict[_msg[:(idx+1)]] = n
        n += 1
        _msg = _msg[idx:]

    return answer
