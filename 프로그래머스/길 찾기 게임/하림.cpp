#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Node{
    int x, y, num;
    Node *left;
    Node *right;
    
    Node(int input_x, int input_y, int input_num){
        x = input_x;
        y = input_y;
        num = input_num;
        left = NULL;
        right  = NULL;
    }
}Node;

// 재귀적으로 이진트리 생성
void insert(Node* parent, Node* child){
    // 자식노드의 x값이 부모노드의 x값보다 작다면
    if(parent->x > child->x){
        if(parent->left != NULL) {
            insert(parent->left, child);
        }
        else {
            parent->left = child;
        }
    }
    // 자식노드의 x값이 부모노드의 x값보다 크다면
    else if(parent->x < child->x){
        if(parent->right != NULL){
            insert(parent->right, child);
        } 
        else {
            parent->right = child;
        }
    }
}

void preorder(vector<int> &answer, Node * node) {
    if(node == NULL){
        return;
    }
    answer.push_back(node->num);
    preorder(answer, node->left);
    preorder(answer, node->right);
}

void postorder(vector<int> &answer, Node * node) {
    if(node == NULL){
        return;
    }
    postorder(answer, node->left);
    postorder(answer, node->right);
    answer.push_back(node->num);
}

bool desc(Node n1, Node n2) {
    return n1.y > n2.y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<Node> nodes;

    for(int i=0; i<nodeinfo.size(); i++){
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int n = i+1;
        Node node(x, y, n);
        nodes.push_back(node);
    }

    sort(nodes.begin(), nodes.end(), desc);

    for(int i=1; i<nodes.size(); i++){
        insert(&nodes[0], &nodes[i]);
    }

    preorder(answer[0], &nodes[0]);
    postorder(answer[1], &nodes[0]);

    return answer;
}
