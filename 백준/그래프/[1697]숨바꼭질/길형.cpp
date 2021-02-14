#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring> // memset
 
using namespace std;
 
#define MAX 100001
 
int N, K;
int visited[MAX];
 
void bfs() 
{
    queue<int> q;
    q.push(N);
    visited[N] = 1;

    while (!q.empty()) 
    {
        int x = q.front();
        q.pop();
 
        if (x == K) return;
 
        for (int i = 0; i < 3; i++) 
        {
            int x_now;
            
            if (i == 0) x_now = x + 1;
            else if (i == 1) x_now = x - 1;
            else if (i == 2) x_now = x * 2;
 
            if (0 <= x_now && x_now < MAX && visited[x_now] == 0) 
            {
                visited[x_now] = visited[x] + 1;
                q.push(x_now);
            }
        }
    }
}
 
int main() 
{
    memset(visited, false, sizeof(visited));
    scanf("%d %d", &N, &K);

    bfs();

    printf("%d\n", visited[K]-1);

    return 0;
}
