#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> nodes;

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int findParent(int x){ //노드 x의 조상 노드를 찾음.
    if(nodes[x] == x) return x;
    else return findParent(nodes[x]);
}

bool isCycle(int a, int b){
    return findParent(a) == findParent(b);
}

void unionNodes(int a, int b){
    //b를 노드 큰 쪽으로 설정
    if(a>b) swap(a, b);
    
    //b의 조상 노드를 a의 조상 노드로 통일
    nodes[findParent(nodes[b])] = findParent(nodes[a]); 
}

int solution(int n, vector<vector<int>> costs) {
    
    //Union-Find에 사용될 배열 초기화.
    for(int i=0;i<n;i++) nodes.push_back(i);
    
    //비용이 작은 순서대로 정렬
    sort(costs.begin(), costs.end(), compare);
    
    //MST(크루스컬 알고리즘) 사용
    int cost = 0, edges = 0; //비용, 연결된 간선의 개수
    for(auto c : costs){
        //종료조건
        if(edges == n-1) return cost;
        
        //사이클을 생성하지 않는다면.
        if(!isCycle(c[0], c[1])){ //Find하기 
            unionNodes(c[0], c[1]); //Union하기 
            cost += c[2];
            edges++; 
        }
    }
    
    return cost;
    
}
