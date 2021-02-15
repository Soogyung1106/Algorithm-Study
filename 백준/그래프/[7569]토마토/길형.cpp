#include<cstdio>
#include<queue>
#define MAX 101
using namespace std;
 
int box[MAX][MAX][MAX];
bool check[MAX][MAX][MAX];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,0,0,-1,1};
int dz[6] = { 0,0,-1,1,0,0 };
int M, N, H;
 
int main()
{
    int day = -1;
    queue<pair<pair<int, int>, int>> q;

    scanf("%d %d %d", &M, &N, &H);

    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &box[i][j][k]);

                if (box[i][j][k] == 1)
                {
                    q.push(make_pair(make_pair(i, j), k));
                    check[i][j][k] = true;
                }
                else if (box[i][j][k] == -1)
                {
                    check[i][j][k] = true;
                }
            }
        }
    }
 
    while (!q.empty())
    {
        int size = q.size();
        ++day; //

        while (size--)
        {
            pair<pair<int, int>, int> now = q.front(); 
            q.pop();
 
            for (int i = 0; i < 6; i++)
            {
                int x_now = now.first.second  + dx[i];
                int y_now = now.first.first + dy[i];
                int z_now = now.second + dz[i];
 
                if (x_now < 0 || x_now >= M || y_now < 0 || y_now >= N || z_now < 0 || z_now >= H) continue;
                if (!check[y_now][x_now][z_now] && box[y_now][x_now][z_now] == 0)
                {
                    check[y_now][x_now][z_now] = true;
                    q.push(make_pair(make_pair(y_now, x_now), z_now));
                }
            }
        }
    }
 
    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(!check[i][j][k])
                {
                    printf("-1");
                    return 0;
                }
            }
        }
    }
 
    printf("%d", day);
    return 0;
}
