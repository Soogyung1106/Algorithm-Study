import sys

input_func = sys.stdin.readline
if __name__ == '__main__':
    N = int(*map(int, input_func().split()))
    P = list(map(int, input_func().split()))
    S = list(map(int, input_func().split()))

    shuffle_cards = P[:]
    goal_card = [0, 1, 2]*(N//3)

    repeat_flag, shuffle_count = True, 0
    while not goal_card == shuffle_cards:

        after_shuffle_cards = [0] * N
        for card in range(N):
            after_shuffle_cards[S[card]] = shuffle_cards[card]

        shuffle_count += 1
        shuffle_cards = after_shuffle_cards

        if after_shuffle_cards == P:
            shuffle_count = -1
            break

    print(shuffle_count)
