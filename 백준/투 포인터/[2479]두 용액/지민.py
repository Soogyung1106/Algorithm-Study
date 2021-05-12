import sys


input = sys.stdin.readline
if __name__ == '__main__':
    N = int(*map(int, input().split()))
    solution = sorted(list(map(int, input().split())))

    a, b = 0, N-1
    min_differ, two_solution = 2000000001, []
    while a < b:
        calc_solution = solution[a] + solution[b]
        if abs(calc_solution) < min_differ:
            min_differ = abs(calc_solution)
            two_solution = [solution[a], solution[b]]
            if calc_solution == 0:
                break

        if calc_solution < 0:
            a += 1
        elif calc_solution > 0:
            b -= 1

    print(' '.join(map(str, two_solution)))
