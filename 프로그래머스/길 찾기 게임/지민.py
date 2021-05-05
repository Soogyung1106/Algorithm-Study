import sys
from collections import defaultdict

sys.setrecursionlimit(10**6)


class Tree:
    def __init__(self, nodes, labeling):
        self.coordinate = max(nodes, key=lambda x: x[1])
        self.label = labeling[tuple(self.coordinate)]
        left = list(filter(lambda x: x[0] < self.coordinate[0], nodes))
        right = list(filter(lambda x: x[0] > self.coordinate[0], nodes))
        
        if left:
            self.left = Tree(left, labeling)
        else:
            self.left = None
        
        if right:
            self.right = Tree(right, labeling)
        else:
            self.right = None


def traversal(node, pre, post):
    pre.append(node.label)
    if node.left:
        traversal(node.left, pre, post)
    
    if node.right:
        traversal(node.right, pre, post)
    post.append(node.label)


def solution(nodeinfo):
    
    labeling = defaultdict()
    for idx in range(len(nodeinfo)):
        labeling[tuple(nodeinfo[idx])] = idx+1
    
    root_node = Tree(nodeinfo, labeling)
    preorder_list, postorder_list = [], []
    
    traversal(root_node, preorder_list, postorder_list)
          
    answer = [preorder_list, postorder_list]
    return answer
