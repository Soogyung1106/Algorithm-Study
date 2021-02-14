#include <iostream>
#include <vector>
using namespace std;
 
#define MAX 51
int M, N, K;
int farm[MAX][MAX];
 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
 
void dfs(int y, int x) 
{
    farm[y][x] = 0; // 이미 방문한 곳은 0으로 변경해서 중복 방문 방지
 
    for(int i=0; i<4; i++) 
    {
        int next_y = y + dx[i];
        int next_x = x + dy[i];
 
        // 예외처리
        if(next_y < 0 || next_y > N || next_x < 0 || next_x > M) continue;
        if(farm[next_y][next_x] == 0) continue;
        dfs(next_y, next_x);
    }
}
 
int main() {
    int T;
    cin >> T;
 
    while(T--) {
        int warm = 0;
        cin >> M >> N >> K;
 
        for(int i=0; i<K; i++) 
        {
            int y, x;
            cin >> x >> y;
            farm[y][x] = 1;
        }
 
        for(int i=0; i<N; i++) 
        {
            for(int j = 0; j < M; j++) 
            {
                if(farm[i][j] != 0) 
                {
                    warm++;
                    dfs(i, j);
                }
            }
        }
        cout << warm << "\n";
    }

    return 0;
}
