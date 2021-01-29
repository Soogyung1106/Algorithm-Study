#2020 카카오 인턴십
from itertools import permutations

def calculation(a, b, operator):
    if operator == '+':
        a = a+b
    elif operator == '-':
        a = a-b
    elif operator == '*':
        a = a*b
    return a

def solution(expression):
    answer = 0
    numbers, operator = [], []
    temp_numbers, temp_operator = [], []
    num = ''
    #숫자, 연산자 분리
    for i in range(len(expression)):
        if expression[i].isdigit():
            num += expression[i]
            if i == len(expression)-1:
                numbers.append(int(num))
        else:
            numbers.append(int(num))
            num = ''
            operator.append(expression[i])
    
    
    operOrder = list(permutations(["+", "-", "*"]))
    for oIdx in operOrder:
        temp_numbers = numbers.copy()
        temp_operator = operator.copy()
        for o in oIdx:
            while len(temp_numbers) != 1:
                if o not in temp_operator:
                    break
                idx = temp_operator.index(o)
                temp_numbers[idx] = calculation(temp_numbers[idx], temp_numbers[idx+1], o)
                del temp_operator[idx]
                del temp_numbers[idx+1]
        answer = max(answer, abs(temp_numbers[0]))
    
        
    return answer
