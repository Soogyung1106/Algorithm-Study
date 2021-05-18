import sys


def calc_subset_weight(weight_list, idx, weight_sum, weight_sum_list):
    if idx >= len(weight_list):
        weight_sum_list.append(weight_sum)
        return

    calc_subset_weight(weight_list, idx+1, weight_sum, weight_sum_list)
    calc_subset_weight(weight_list, idx+1, weight_sum+weight_list[idx], weight_sum_list)


input = sys.stdin.readline
if __name__ == '__main__':
    N, S = map(int, input().split())
    weights = list(map(int, input().split()))

    a_weights, b_weights = weights[:N//2], weights[N//2:]
    a_sum, b_sum = [], []
    calc_subset_weight(a_weights, 0, 0, a_sum)
    calc_subset_weight(b_weights, 0, 0, b_sum)
    a_sum. sort()
    b_sum.sort()

    a_cnt, b_cnt, cnt = 0, 0, 0
    a_len, b_len = len(a_sum), len(b_sum)
    a, b = 0, len(b_sum) - 1
    while a < a_len and b >= 0:
        calc_num = a_sum[a] + b_sum[b]

        if calc_num == S:
            a_cnt, b_cnt = 1, 1
            a_end, b_end = a, b
            a += 1
            while a < a_len and a_sum[a] == a_sum[a_end]:
                a_cnt += 1
                a += 1
            b -= 1
            while b >= 0 and b_sum[b] == b_sum[b_end]:
                b_cnt += 1
                b -= 1

            cnt += (a_cnt * b_cnt)

        elif calc_num <= S:
            a += 1
        else:
            b -= 1

    print(cnt-1 if S == 0 else cnt)

