import sys


input_func = sys.stdin.readline
if __name__ == '__main__':
    input_polynomial = str(*map(str, input_func().split()))

    integral, temp_polynomial = '', ''
    idx, count, operator = 0, 0, ''
    while True:
        if input_polynomial[idx].isdigit():
            temp_polynomial += input_polynomial[idx]
            if idx == len(input_polynomial)-1:
                if int(temp_polynomial) == 0:
                    pass
                elif int(temp_polynomial) != 1:
                    integral += temp_polynomial + 'x'
                else:
                    integral += 'x'
                break
        elif input_polynomial[idx] == 'x':
            num = int(temp_polynomial)//2
            if num != 1:
                integral += str(num)
            integral += 'xx'
            temp_polynomial = ''
            if idx == len(input_polynomial)-1:
                break
        else:
            integral += input_polynomial[idx]

        idx += 1

    print(integral+'+W' if integral else 'W')
