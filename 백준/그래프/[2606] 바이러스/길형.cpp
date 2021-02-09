#include <cstdio>
#include <iostream>

#define MAX 101

int map[MAX][MAX];
bool visit[MAX];
int computer = 0;
int answer = 0;

void dfs(int n) 
{
	answer++;
	visit[n] = true;

	for (int i = 1; i <= computer; i++) 
	{
		if (map[n][i] && !visit[i])
			dfs(i);
	}
}

int main() 
{
	int n;
	int x, y;

	scanf("%d %d", &computer, &n);

	for (int i = 0; i < n; i++) 
	{
		scanf("%d %d", &x, &y);
		map[x][y] = map[y][x] = 1;
	}

	dfs(1);
	printf("%d\n", answer - 1);

	return 0;
}
