import sys
from collections import defaultdict

if __name__ == '__main__':
    tree_dict = defaultdict(int)
    tree_count = 0
    for input_line in sys.stdin:
        if input_line == '\n':
            break
        input_tree = input_line.rstrip()
        tree_dict[input_tree] += 1
        tree_count += 1

    for tree, count in sorted(tree_dict.items()):
        ratio = (count/tree_count)*100
        print(f'{tree} {ratio:.4f}')
