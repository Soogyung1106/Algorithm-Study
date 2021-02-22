import sys

if __name__=="__main__":
    N = int(*map(int, sys.stdin.readline().split()))
    people = []
    rank = [1]*N

    for _ in range(N):
        people.append(list(map(str, sys.stdin.readline().split(' '))))

    for i in range(N):
        w1, h1 = people[i]
        for j in range(N):
            w2, h2 = people[j]
            if w1 < w2 and h1 < h2:
                rank[i] += 1
    print(' '.join(map(str, rank)))
