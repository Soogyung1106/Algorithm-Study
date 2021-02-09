#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <queue>

#define MAX 101

#pragma warning(disable:4996)

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int n = 0, m = 0;
	map<int, vector<int>> network;
	int answer = 0;
	queue<int> q;
	bool visit[MAX] = { false };

	scanf("%d\n%d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		network[a].push_back(b);
	}
	
	for (int i = 0; i < network[1].size(); i++)
	{
		q.push(network[1][i]);
		answer++;
	}

	while (!q.empty())
	{
		int idx = q.front();
		visit[idx] = true;
		q.pop();

		for (int i = 0; i < network[idx].size(); i++)
		{
			q.push(network[idx][i]);
			if(!visit[network[idx][i]]) answer++;
		}
	}

	cout << answer << endl;

	return 0;
}
