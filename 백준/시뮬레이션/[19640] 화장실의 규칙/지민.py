import sys
from collections import deque
from queue import PriorityQueue


input_func = sys.stdin.readline
if __name__ == '__main__':
    N, M, K = map(int, input_func().split())
    waiting_lines, idx = [deque() for _ in range(M)], 0
    for n in range(N):
        D, H = map(int, input_func().split())
        line_number = idx%M
        waiting_lines[line_number].append((D*(-1), H*(-1), line_number, n+1))
        idx += 1

    out_queue = PriorityQueue()
    for idx in range(M):
        if waiting_lines[idx]:
            next_worker = waiting_lines[idx].popleft()
            out_queue.put(next_worker)

    worker, count = -1, 0
    while worker != (K+1):
        _, _, out_worker_line, worker = out_queue.get()
        count += 1
        if waiting_lines[out_worker_line]:
            next_worker = waiting_lines[out_worker_line].popleft()
            out_queue.put(next_worker)


    print(count-1)
