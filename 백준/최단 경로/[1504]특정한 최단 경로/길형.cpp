#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <climits>
#define MAX 801
#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[MAX];
int N, M; // N : 정점의 개수, M : 간선의 개수

vector<int> dijkstra(int start, int vertex)

{
	vector<int> distance(vertex, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// priority_queue<T, Container, Compare> :T는 원하는 자료형, Container는 vector와 같은 컨테이너이며 Compare는 비교함수 클래스이다.

	distance[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int dist = pq.top().first; // priority_queue의 가장 위에 있는 top의 first를 비용으로 설정
		int now = pq.top().second; // priority_queue의 가장 위에 있는 top의 second를 현재 정점(노드)로 설정

		pq.pop();

		if (distance[now] < dist)
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int near = graph[now][i].first;
			int near_distance = dist + graph[now][i].second;

			//업데이트할 때마다 trace도 업데이트

			if (distance[near] > near_distance)
			{
				distance[near] = near_distance;
				pq.push({ near_distance, near });
			}
		}
	}
	return distance;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();

	cin >> N >> M;

	N++;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	int node1, node2;
	cin >> node1 >> node2;

	vector<int> result = dijkstra(1, N);
	vector<int> temp1 = dijkstra(node1, N);
	vector<int> temp2 = dijkstra(node2, N);

	/*
	두 가지 경우
	Start -> A -> B -> End
	Start -> B -> A -> End
	*/

	int answer = min({ result[node1] + temp1[node2] + temp2[N - 1], result[node2] + temp2[node1] + temp1[N - 1] });

	if (answer >= INF || answer < 0)
	{
		cout << -1 << "\n";
	}
	else cout << answer << "\n";

	return 0;
}
