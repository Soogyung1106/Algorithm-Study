import sys
from collections import defaultdict


def make_number(_num, dp):
    if len(_num) == 1:
        dp[_num] = 1
        return _num

    else:
        left_dp = make_number(_num[:len(_num)-1], dp)
        right_dp = make_number(_num[1:], dp)

        if left_dp != right_dp:
            dp[_num] = dp[left_dp]+dp[right_dp]
        else:
            dp[_num] = dp[left_dp]

        return _num


input_func = sys.stdin.readline
if __name__ == '__main__':
    N = str(*map(str, input_func().split()))

    dp = defaultdict(int)
    make_number(N, dp)

    print(dp[N])
