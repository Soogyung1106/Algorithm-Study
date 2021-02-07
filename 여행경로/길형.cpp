#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check=false;
bool visited[10001];
vector<string> answer;

void dfs(vector<vector<string>> tickets, string next, vector<string> str)
{
    if(str.size() == tickets.size()) // 모든 경로 순회를 다 한 경우
    {
        str.push_back(next);
        check = true;
        answer = str; 
        
        return;
    }
    
    for(int i = 0 ;i < tickets.size(); i++)
    {
        if(check == true) break; // 모든 경로를 다 돌았으니까 break
        
        if(next == tickets[i][0] && !visited[i]) 
        {
            str.push_back(tickets[i][0]);
            visited[i] = true;
            dfs(tickets, tickets[i][1], str);
            // 해당 목적지가 출발 지점으로 없는 경우
            str.pop_back();
            visited[i] = false;
        }
    }
    
    
}
vector<string> solution(vector<vector<string>> tickets){
    
    
    sort(tickets.begin(), tickets.end()); //정렬
    
    for(int i = 0 ; i < tickets.size() ; i++)
    {
        if(tickets[i][0] == "ICN")
        {
            visited[i] = true; //ICN 공항부터 방문 시작
            answer.push_back(tickets[i][0]);
            
            dfs(tickets, tickets[i][1], answer);
    
            if(check == true) return answer;
            
            answer.pop_back();
            visited[i] = false; //모든 정점을 방문하지 못했으면 방문 취소함 다음 ICN 공항부터 시작
        }
    }
    
    return answer;
}
