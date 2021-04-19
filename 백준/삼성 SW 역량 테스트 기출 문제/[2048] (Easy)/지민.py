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


def move_blocks(times, graph, process):
    global max_value
    if times == 5:
        print('5', graph)
        _game_board_temp = sum(graph, [])
        max_value = max(max_value, max(_game_board_temp))
        print(max_value)
        return

    _graph = [r[:] for r in graph]
    _process = [x for x in process]

    for idx in range(4):
        if idx in (0, 1):
            _graph = list(map(list, zip(*_graph)))
            print('transpose', _graph)

        _process += [idx]

        func = functions[idx]
        print('times', times, _process, func)
        _graph = func(_graph)

        if idx in (0, 1):
            _graph = list(map(list, zip(*_graph)))

        print(_graph)
        move_blocks(times + 1, _graph, _process)
        _graph = [r[:] for r in graph]
        _process = [x for x in process]


if __name__ == '__main__':
    N = int(*map(int, sys.stdin.readline().split()))
    game_board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    functions = {0: move_leftward, 1: move_rightward, 2: move_leftward, 3: move_rightward}

    max_value = 0
    process = []
    move_blocks(0, game_board, process)
    print(max_value)
