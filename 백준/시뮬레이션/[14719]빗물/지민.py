import sys


input_func = sys.stdin.readline
if __name__ == '__main__':
    H, W = map(int, input_func().split())
    blocks = list(map(int, input_func().split()))

    rain = 0
    for w_idx in range(W):
        max_left = max(blocks[:w_idx+1])
        max_right = max(blocks[w_idx:])

        blocked_height = min(max_left, max_right)

        rain += abs(blocks[w_idx]-blocked_height)
