#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001

bool visit1[MAX];
bool visit2[MAX];
int vec[MAX][MAX];

using namespace std;

void DFS(int index, int n)
{
	cout << index << " ";

	for (int i = 0; i <= n; i++)
	{
		if (!visit1[i] && vec[index][i])
		{
			visit1[i] = true; // 방문했음
			DFS(i, n);
		}
	}
}

void BFS(int index, int n, queue<int> &q)
{
	q.push(index);
	visit2[index] = true;

	while (!q.empty())
	{
		index = q.front();
		q.pop();

		cout << index << " ";

		for (int i = 0; i <= n; i++)
		{
			if (!visit2[i] && vec[index][i])
			{
				visit2[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	int a, b;
	int n, m, v;
	queue<int> q;

	cin >> n >> m >> v; // 정점의 개수 n, 간선의 개수 m, 시작번호 v

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		vec[a][b] = vec[b][a] = 1;
	}

	visit1[v] = true;
	DFS(v, n);
	cout << endl;

	BFS(v, n, q);
	cout << endl;

	return 0;
}
