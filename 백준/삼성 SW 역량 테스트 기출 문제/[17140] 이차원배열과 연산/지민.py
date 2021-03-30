import sys
from collections import Counter


def R(matrix):
    max_len = 0
    for i in range(len(matrix)):
        new_matrix = []
        count_matrix = Counter(matrix[i])
        count_matrix = sorted(list(count_matrix.items()), key=lambda x: (x[1], x[0]))
        for key, value in count_matrix:
            if key == 0:
                continue
            new_matrix.extend([key, value])
        new_len = len(new_matrix)
        if new_len > 100:
            new_matrix = new_matrix[:100]

        matrix[i] = new_matrix
        max_len = max(max_len, new_len)

    for i in range(len(matrix)):
        m_len = len(matrix[i])
        if m_len < max_len:
            matrix[i].extend([0]*(max_len-m_len))

    return matrix, max_len


def C(matrix):
    _matrix = list(map(list, zip(*matrix)))
    max_len = 0
    for i in range(len(_matrix)):
        new_matrix = []
        count_matrix = Counter(_matrix[i])
        count_matrix = sorted(list(count_matrix.items()), key=lambda x: (x[1], x[0]))
        for key, value in count_matrix:
            if key == 0:
                continue
            new_matrix.extend([key, value])
        new_len = len(new_matrix)
        if new_len > 100:
            new_matrix = new_matrix[:100]
        _matrix[i] = new_matrix
        max_len = max(max_len, new_len)

    for i in range(len(_matrix)):
        m_len = len(_matrix[i])
        if m_len < max_len:
            _matrix[i].extend([0]*(max_len-m_len))

    return list(map(list, zip(*_matrix))), max_len


if __name__=="__main__":
    r, c, k = map(int, sys.stdin.readline().split())
    A = [list(map(int, sys.stdin.readline().split())) for _ in range(3)]

    time = 0
    while True:
        row_len, column_len = len(A), len(A[0])
        if r <= len(A) and c <= len(A[0]) and A[r-1][c-1] == k:
            print(time)
            break
        elif time == 100:
            print(-1)
            break

        #count the number of row and column
        if row_len >= column_len:
            A, row_len = R(A)
        else:
            A, column_len = C(A)

        time += 1
