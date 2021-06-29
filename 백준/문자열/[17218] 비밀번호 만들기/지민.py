import sys


input_func = sys.stdin.readline
if __name__ == '__main__':
    first = str(*map(str, input_func().split()))
    second = str(*map(str, input_func().split()))

    lcs = [['' for _ in range(len(second)+1)] for _ in range(len(first)+1)]

    for i in range(1, len(first)+1):
        for j in range(1, len(second)+1):
            if first[i-1] == second[j-1]:
                lcs[i][j] = lcs[i-1][j-1]+first[i-1]
            else:
                if len(lcs[i-1][j]) < len(lcs[i][j-1]):
                    lcs[i][j] = lcs[i][j-1]
                else:
                    lcs[i][j] = lcs[i-1][j]


    print(lcs[-1][-1])
