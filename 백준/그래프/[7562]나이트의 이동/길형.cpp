#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
 
int map[310][310];
int T;
int len;
int startX, startY, endX, endY;
 
queue<pair<int, int>> q;
int visited[310][310];
 
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
 
void BFS()
{
    visited[startX][startY] = 1;
    q.push({startX, startY});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        
        for(int i = 0; i < 8; i++)
        {
            int x_next = x+dx[i];
            int y_next = y+dy[i];

            if(x_next >= 0 && x_next < len && y_next >= 0 && y_next < len)
            {
                if( visited[x_next][y_next] == 0)
                {
                    visited[x_next][y_next] = visited[x][y] + 1;
                    q.push({x_next, y_next});
                }
            }
            
        }
    }
}
 
int main(void)
{
    scanf("%d", &T);
    
    for(int n = 1; n <= T; n++)
    {            
        cin >> len;
        cin >> startX >> startY >> endX >> endY;
        
        BFS();
        
        cout << visited[endX][endY]-1 << endl;

        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                visited[i][j] = 0;
            }
        }
    }
        
    return 0;
}
