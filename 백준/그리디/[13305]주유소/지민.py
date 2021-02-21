import sys


if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    distance = list(map(int, sys.stdin.readline().split(' ')))
    price = list(map(int, sys.stdin.readline().split(' ')))

    min_price = price[0]
    answer = distance[0] * min_price
    for i in range(1, N-1):
        if price[i] < min_price:
            min_price = price[i]
        answer += min_price*distance[i]

    print(answer)
