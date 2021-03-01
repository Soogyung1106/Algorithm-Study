#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>

#define INF 987654321
#define endl "\n"
#define MAX 2001

using namespace std;

/*
T : 테스트케이스 개수
n : 정점(교차로), m :  간선(도로), t :  목적지 후보 개수
s : 출발지점 , g,h : 예술가들이 지나간 교차로
해당 문제는 양방향 그래프
*/

int n, m, t; // n : 정점, m : 간선, t : 목적지 후보의 개수
int s, g, h; // s: 시작점, g,h : 지나간 교차로
vector<pair<int, int>> graph[MAX];
vector<int> route;

vector<int> dijkstra(int start)
{
	vector<int> distance(n + 1, INF); // 각 노드로 이동하는데 필요한 시간 메모제이션, INF로 초기화
	distance[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (cost > distance[now]) continue;
		for (int i = 0; i < graph[now].size(); i++)
		{
			int near = graph[now][i].first;
			int next_cost = cost + graph[now][i].second;

			if (next_cost < distance[near])
			{
				distance[near] = next_cost;
				pq.push({ next_cost, near });
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

	int T; // T : Testcase
	cin >> T;

	while (T--)
	{
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
		}
		int a, b, c;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			graph[a].push_back({ b,c });
			graph[b].push_back({ a,c });
		}

		int temp;
		route.clear();

		for (int j = 0; j < t; j++)
		{
			cin >> temp;
			route.push_back(temp);
		}

		sort(route.begin(), route.end());

		vector<int> root = dijkstra(s);
		vector<int> branch1 = dijkstra(g);
		vector<int> branch2 = dijkstra(h);

		vector<int> result;

		for (int i = 1; i <= n; i++)
		{
			if (root[i] == root[g] + branch1[h] + branch2[i] || root[i] == root[h] + branch2[g] + branch1[i])
			{
				result.push_back(i);
			}
		}

		for (int i = 0; i < route.size(); i++)
		{
			int here = route[i];
			for (int j = 0; j < result.size(); j++)
			{
				if (here == result[j])
				{
					cout << here << " ";
				}
			}
		}
		cout << endl;
	}

	return 0;
}
