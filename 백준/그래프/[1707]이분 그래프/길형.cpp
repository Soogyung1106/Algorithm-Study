#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 20001

using namespace std;
 
int T;
int V, E; 
vector<int> graph[MAX];
int visited[MAX];
 
void BFS(int start)
{    
    queue<int> q;
    
    q.push(start);
    visited[start] = 1; // 0 : No, 1: Red, 2:Blue
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < graph[x].size(); i++)
        {
            if(visited[x] == 1) // Red
            {
                if(visited[graph[x][i]] == 0) // 인접정점 Blue
                {
                    q.push(graph[x][i]);
                    visited[graph[x][i]] = 2;    
                } 
            }
            else if(visited[x] == 2) // Blue
            {
                if(visited[graph[x][i]] == 0) // 인접정점 Red
                {
                    q.push(graph[x][i]);
                    visited[graph[x][i]] = 1;    
                } 
            }
        }
    }
}
 
bool isBinary(void) 
{
    for(int i = 1; i <= V; i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            if(visited[i] == visited[graph[i][j]]) // 인접정점이 같은 색이면 -> 이분그래프 X -> false
            {
                return false; 
            }
        }
    }
    
    return true;
}
 
int main(void)
{
    cin >> T; // T : 테스트 케이스 개수
    
    while(T--)
    {
        cin >> V >> E; // V : 정점의 개수, E : 간선의 개수
        
        for(int i = 1; i <= V; i++)
        {
            graph[i].clear();
            visited[i] = 0;
        }
        
        for(int i = 1; i <= E; i++)
        {
            int from, to;
            cin >> from >> to;
            
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        for(int i = 1; i <= V; i++)
        {
            if(visited[i] == 0)
            {
                BFS(i);    
            }
        }
        
        if(isBinary())
        {
            cout << "YES" << endl;    
        } 
        else
        {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
