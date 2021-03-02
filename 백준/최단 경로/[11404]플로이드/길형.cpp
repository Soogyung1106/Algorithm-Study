/*
[문제]
n(2 ≤ n ≤ 100)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다. 각 버스는 한 번 사용할 때 필요한 비용이 있다.

모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 도시의 개수 n이 주어지고 둘째 줄에는 버스의 개수 m이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 버스의 정보는 버스의 시작 도시 a, 도착 도시 b, 한 번 타는데 필요한 비용 c로 이루어져 있다. 시작 도시와 도착 도시가 같은 경우는 없다. 비용은 100,000보다 작거나 같은 자연수이다.

시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.

[출력]
n개의 줄을 출력해야 한다. i번째 줄에 출력하는 j번째 숫자는 도시 i에서 j로 가는데 필요한 최소 비용이다. 만약, i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력한다.


[플로이드 와샬]
1.모든 정점에서 모든 정점으로의 최단 경로를 한번에 구한다. 즉 정점과 정점, 모든 쌍의 최단 경로를 구하게 된다.
	모든 쌍을 표현하는 행렬(이차원 배열)을 선언하고 다이나믹 프로그래밍 방식으로 각각의 원소들(각 쌍의 최단거리)을 업데이트 해나간다.
		업데이트 기준 -> 현재 거쳐가는 정점

2.거쳐가는 정점을 기준으로 알고리즘을 수행한다.
	i 에서 j 로 가는데 해당 정점을 경유해서 가는 것이 더 빠르다면 그 정점을 거쳐서 가는걸로 업데이트 한다.

[참고] https://ansohxxn.github.io/algorithm/floyd/
*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
using namespace std;

const int MAX = 101;
const int INF = 987654321;

int graph[MAX][MAX];
int city, bus;

void floyd_warshall()
{
	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			for (int k = 1; k <= city; k++)
			{
				if (graph[j][i] != INF && graph[i][k] != INF)
				{
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
				}
			}
		}
	}
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
	int from, to, weight;

	cin >> city >> bus;

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < bus; i++) 
	{    
		cin >> from >> to >> weight;

		if (graph[from][to] > weight)
			graph[from][to] = weight;
	}

	floyd_warshall();

	for (int i = 1; i <= city; i++) 
	{
		for (int j = 1; j <= city; j++)
		{
			if (i == j || graph[i][j] == INF)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << graph[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
