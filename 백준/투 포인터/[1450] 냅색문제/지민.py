import sys


def calc_subset_weight(weight_list, idx, weight_sum, weight_sum_list):
    if idx >= len(weight_list):
        weight_sum_list.append(weight_sum)
        return

    calc_subset_weight(weight_list, idx+1, weight_sum, weight_sum_list)
    calc_subset_weight(weight_list, idx+1, weight_sum+weight_list[idx], weight_sum_list)


def binarysearch_lowerbound(arr, start, end, key):
    while start < end:
        mid = (start+end) // 2
        if arr[mid] <= key:
           start = mid + 1
        else:
            end = mid
    return end


input = sys.stdin.readline
if __name__ == '__main__':
    N, C = map(int, input().split())
    weights = list(map(int, input().split()))

    a_weights, b_weights = weights[:N//2], weights[N//2:]
    a_sum, b_sum = [], []
    calc_subset_weight(a_weights, 0, 0, a_sum)
    calc_subset_weight(b_weights, 0, 0, b_sum)
    b_sum.sort()

    cnt = 0
    for idx in a_sum:
        if C-idx < 0:
            continue
        cnt += binarysearch_lowerbound(b_sum, 0, len(b_sum), C-idx)

    print(cnt)
