#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[201];

void dfs(int i, vector<vector<int>> computers){
    // computers의 i노드와 연결된 모든 노드 탐색
    // i노드 방문 표시
    visited[i] = true;
    
    for(int j=0;j<computers.size();j++)
        if(computers[i][j] == 1 && !visited[j])
            dfs(j, computers);
    
}

int solution(int n, vector<vector<int>> computers) {
        
    int answer = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){ 
            dfs(i, computers);
            answer++;
        }
    }
     
    return answer;
}
