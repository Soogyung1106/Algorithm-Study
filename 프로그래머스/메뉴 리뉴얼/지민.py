#2021 KAKAO BLIND RECRUITMENT
from collections import defaultdict
from itertools import combinations

def solution(orders, course):
    answer = []
    
    for course_num in course:
        orders_dict = defaultdict(int)
        comb_list = []
        for order in orders:
            comb_list.extend(list(map(list, combinations(order, course_num))))
        
        max_num = 0
        for comb in comb_list:
            comb.sort()
            comb_string = ''.join(comb)
            orders_dict[comb_string] += 1
            if orders_dict[comb_string] != 1:
                max_num = max(max_num, orders_dict[comb_string])

        answer.extend([x[0] for x in orders_dict.items() if x[1] == max_num])

        
    return sorted(answer)
