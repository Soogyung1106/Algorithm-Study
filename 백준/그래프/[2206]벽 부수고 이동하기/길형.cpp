#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
bool visit[2][1001][1001] = {false, }; // visit[0][-][-] 아직 벽 안부숨, visit[1][-][-] 벽 부숨
int map[1001][1001] = {0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
 
int N = 0, M = 0;
 
queue<pair<int, pair<int, int> > > q; // <a, <b, c>> pair 2중 구조 총 3개의 요소 
 
int BFS()
{
    q.push({ 0, {1, 1} }); // 0 벽 안부숨, (1,1) 시작
 
    visit[0][1][1] = true;
 
    int answer = 1; // (1,1)도 포함
 
    while (!q.empty())
    {
        int qSize = q.size();
 
        while (qSize--)
        {
            int current = q.front().first;
            int y = q.front().second.first;
            int x = q.front().second.second;
            
            q.pop();
 
            if (y == N && x == M) // 목적지 도달
            {
                return answer;
            }
 
            for (int i = 0; i < 4; i++)
            {
                int y_next = y + dy[i];
                int x_next = x + dx[i];
                if (y_next <= 0 || y_next > N || x_next <= 0 || x_next > M || visit[current][y_next][x_next]) continue; // 범위체크
                if (current == 0) // 벽 부술 기회 O
                {
                    if (map[y_next][x_next] == 1) // 벽이 있으면 부순다.
                    {
                        q.push({ 1, {y_next, x_next} }); 
                        visit[1][y_next][x_next] = true;
                    }
                    else if (map[y_next][x_next] == 0) // 벽이 아님
                    {
                        q.push({ 0, { y_next, x_next } });
                        visit[0][y_next][x_next] = true;
                    }
                }
                else if (current == 1) // 벽 부술 기회 X
                {
                    if (map[y_next][x_next] == 0)
                    {
                        q.push({ 1, { y_next, x_next } });
                        visit[1][y_next][x_next] = true;
                    }
                }
            }
        }
 
        ++answer;
    }
 
    return -1; // 도달 실패
}
 
int main(void)
{
    scanf("%d %d", &N, &M);
 
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
 
    printf("%d\n", BFS());
 
    return 0;
}
