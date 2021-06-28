import sys


def find_possible_numbers(_number):
    _possible_number = []

    for _n in range(10):
        flag = True
        for _idx in range(15):
            if _number[_idx] == '#' and digits[_n][_idx] == '.':
                flag = False
                break
        if flag:
            _possible_number.append(_n)

    return _possible_number


input_func = sys.stdin.readline
if __name__ == '__main__':

    digits = ['####.##.##.####', '..#..#..#..#..#', '###..#####..###', '###..####..####', '#.##.####..#..#',
              '####..###..####', '####..####.####', '###..#..#..#..#', '####.#####.####', '####.####..####']

    N = int(*map(int, input_func().split()))
    numbers = []*5
    for _ in range(5):
        temp = list(*map(str, input_func().split()))
        for idx in range(0, N*4-1, 4):
            numbers.append(temp[idx:idx+3])

    possible_numbers, average, break_flag = [], [], False
    for n in range(N):
        number = ''
        for idx in range(n, N*5, N):
            temp_number = numbers[idx]
            number += ''.join(temp_number)

        possible_list = find_possible_numbers(number)
        if possible_list:
            num_sum = sum(possible_list)*pow(10, N-(n+1))
            average.append(num_sum/len(possible_list))
        else:
            average = [-1]
            break

    print(sum(average))
