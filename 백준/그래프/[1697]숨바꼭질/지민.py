from collections import deque

def bfs(start, end):
    route = deque([start])
    routeSub = deque()
    visited = [0]*100001
    count = 0

    next = [-1, 1, 2]
    while route:
        for r in route:
            routeSub.append(r)
        route.clear()
        count += 1

        while routeSub:
            s = routeSub.popleft()
            for i in range(3):
                if i == 2:
                    ns = s * next[i]
                else:
                    ns = s + next[i]

                if 0 <= ns <= 100000:
                    if visited[ns] == 0:
                        visited[ns] = 1
                        route.extend([ns])
                        if ns == end:
                            return count

    return count


if __name__=="__main__":
    S, Sis = map(int, input().split())

    if S == Sis:
        print('0')
    else:
        bfsResult= bfs(S, Sis)
        print(bfsResult)


