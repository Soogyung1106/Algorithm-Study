#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer; //경로를 저장할 배열
vector<bool> visited;

/*
- visited[i]가 true는 tickets i행 이미 방문했다는 뜻.
- tickets를 돌면서 to에 해당하는 from을 찾음. answer에 경로 push
- 해당하는 from이 없다면 리턴. answer에서도 경로 pop, visited 원상복귀
- 기저조건: 모든 행이 방문되어 있다면... return
*/
bool dfs(string from, vector<vector<string>> tickets){
    
    answer.push_back(from);
    
    for(int i=0;i<tickets.size();i++){
        if(!visited[i] && tickets[i][0] == from){
            visited[i] = true;
            if(dfs(tickets[i][1], tickets)) return true;
            else{
                visited[i] = false;
                answer.pop_back();
            }
        }//if
    }//for
    
    //못 찾은 경우
    for(int i=0;i<visited.size();i++)
        if(!visited[i]) return false;
    
    //다 순회한 경우
    return true;
    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    //사전순 정렬
    sort(tickets.begin(), tickets.end()); 
    visited.resize(tickets.size());
    //ICN부터 출발해서 경로를 찾음 
    dfs("ICN", tickets); 

    return answer;
}
