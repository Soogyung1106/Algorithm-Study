import sys


def move_leftward(graph):
    for r in range(N):
        g_row = graph[r]
        non_zero_row = [x for x in g_row if x != 0]
        for c in range(1, len(non_zero_row)):
            if non_zero_row[c-1] == non_zero_row[c]:
                non_zero_row[c-1] += non_zero_row[c]
                non_zero_row[c] = 0

        non_zero_row = [x for x in non_zero_row if x != 0]

        zero_count = N-len(non_zero_row)
        non_zero_row.extend([0]*zero_count)
        graph[r] = non_zero_row

    return graph


def move_rightward(graph):
    for r in range(N):
        g_row = graph[r]
        non_zero_row = [x for x in g_row if x != 0]
        for c in range(len(non_zero_row)-1, 0, -1):
            if non_zero_row[c] == non_zero_row[c-1]:
                non_zero_row[c] += non_zero_row[c-1]
                non_zero_row[c-1] = 0

        non_zero_row = [x for x in non_zero_row if x != 0]

        zero_count = N-len(non_zero_row)
        non_zero_row = [0]*zero_count + non_zero_row
        graph[r] = non_zero_row

    return graph


def move_blocks(times, graph):
    global max_value
    if times == 5:
        _game_board_temp = sum(graph, [])
        max_value = max(max_value, max(_game_board_temp))
        return

    _graph = [r[:] for r in graph]

    for idx in range(4):
        if idx in (0, 1):
            _graph = list(map(list, zip(*_graph)))

        func = functions[idx]
        _graph = func(_graph)

        if idx in (0, 1):
            _graph = list(map(list, zip(*_graph)))

        move_blocks(times + 1, _graph)
        _graph = [r[:] for r in graph]


if __name__ == '__main__':
    N = int(*map(int, sys.stdin.readline().split()))
    game_board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    functions = {0: move_leftward, 1: move_rightward, 2: move_leftward, 3: move_rightward}

    max_value = 0
    move_blocks(0, game_board)
    print(max_value)
