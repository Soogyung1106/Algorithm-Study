from collections import defaultdict


def solution(gems):
    
    gems_number = len(gems)
    all_gem = set(gems)
    
    answer = [1, gems_number]
    gem_dict = defaultdict(int)
    gem_dict[gems[0]] += 1
    start, end = 0, 0
    min_len = gems_number
    while start < gems_number:
        if len(gem_dict) != len(all_gem):
            end += 1
            
            if end >= gems_number:
                break
            gem_dict[gems[end]] += 1
        
        else:
            if end-start < min_len:
                min_len = end-start
                answer = [start+1, end+1]
            
            gem_dict[gems[start]] -= 1
            if gem_dict[gems[start]] <= 0:
                del gem_dict[gems[start]]
            start += 1
                
    return answer
