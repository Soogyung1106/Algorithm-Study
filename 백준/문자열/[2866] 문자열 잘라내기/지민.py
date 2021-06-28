import sys


input_func = sys.stdin.readline
if __name__ == '__main__':
    R, C = map(int, input_func().split())
    input_string = [list(*map(list, input_func().split())) for _ in range(R)]

    start, end, count = 0, R-1, R

    while start <= end:
        mid = (start+end)//2
        search_flag = False
        compare_set = set()
        for j in range(C):
            word = ''
            for i in range(mid, R):
                word += input_string[i][j]

            if word not in compare_set:
                compare_set.add(word)
            else:
                search_flag = True
                if count > mid:
                    count = mid
                else:
                    break

        if search_flag:
            end = mid-1
        else:
            start = mid+1

    print(count-1)
