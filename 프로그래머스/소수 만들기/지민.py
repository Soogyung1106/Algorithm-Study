#Summer/Winter Coding(~2018)
from itertools import combinations

def eratos(n):
    sieve = [True] * n
    max = int(n**0.5)+1
    for i in range(2, max):
        if sieve[i] == True:
            for j in range(i+i, n, i):
                sieve[j] = False
                
    return [i for i in range(2, n) if sieve[i]==True]
            

def solution(nums):
    answer = 0
    nums_list = list(combinations(nums, 3))
    sum_list = []
    
    #조합의 합으로 만들 수 있는 숫자의 리스트
    for comNum in nums_list:
        sum = 0
        for idx in range(len(comNum)):
            sum += comNum[idx]
        sum_list.append(sum)
    
    #에라토스테네스의 체
    eratos_list = eratos(max(sum_list)+1)
    #확인
    for num in sum_list:
        if num in eratos_list:
            answer += 1
   
    return answer
