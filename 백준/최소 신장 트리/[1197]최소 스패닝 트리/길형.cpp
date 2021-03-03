/*
[문제]
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

[입력]
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

[출력]
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.
*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#define endl "\n"

using namespace std;

typedef pair<int, int> PAIR;

vector<pair<int, int>> graph[10001];
int visit[10001];	//방문을 확인하는 배열

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	int sum = 0 ;	//최소 스패닝 트리의 가중치
	int V, E;		// 정점의 개수, 간선의 수
	int start = 1;	// 시작정점의 번호
	cin >> V >> E; 

	while(E--)
	{
		int from, to, val;
		cin >> from >> to >> val;

		graph[from].push_back(make_pair(to, val));
		graph[to].push_back(make_pair(from, val));
	}

	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq; //cost 로 우선순위 정렬을 해야하기 때문에 pair{cost, vertex} 순서로 넣어준다.

	for (int i = 0; i < graph[start].size(); i++) 
	{
		int next = graph[start][i].first;
		int nextCost = graph[start][i].second;

		pq.push(make_pair(nextCost, next));
	}
	
	visit[start] = 1;

	while (!pq.empty()) 
	{
		int now = pq.top().second;
		int now_cost = pq.top().first;

		pq.pop();

		if (visit[now] == 1) 
		{
			continue;
		}

		visit[now] = 1;

		sum += now_cost;

		for (int i = 0; i < graph[now].size(); i++) 
		{
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;

			pq.push(make_pair(nextCost, next));
		}
	}
	cout << sum << endl;

	return 0;
}
