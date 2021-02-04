#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visit[201]; // DFS 방문한 노드 체크

void dfs(int now, int n, vector<vector<int>> &computers)
{
    visit[now] = true;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(!visit[i] && computers[now][i]) // 방문한적이 없고, computers[now][i]가 1이면
            dfs(i, n, computers); // 어차피 computers[i][i] 는 1이여도 visit[now]에서 먼저 바꾸기 때문에 자기자신을 순회할 일은 없음.
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(!visit[i])
        {
            answer++;
            dfs(i, n, computers); 
            // 순회하면서 visit체크, 그러면 방문했던 노드는 다 1이되고 결국 연결 안되어있는 것들만 순회하면서 answer + 1
        }
    }
    
    return answer;
}
