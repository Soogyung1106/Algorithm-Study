import sys

if __name__=="__main__":
    N = int(sys.stdin.readline())
    A = list(map(int, sys.stdin.readline().split(' ')))
    nge = [-1]*N
    temp = []

    for idx in range(N):
        #인덱스 저장 스택에 데이터가 존재하고
        #가장 최신의 인덱스 A가 현재 비굣값보다 작을 때
        #NGE리스트를 갱신
        while temp and A[temp[-1]] < A[idx]:
            nge[temp.pop()] = A[idx]
        #인덱스 저장 스택 갱신
        temp.append(idx)

    print(' '.join(map(str, nge)))
