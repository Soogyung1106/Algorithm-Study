#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main() {

	//입력
	int V, E; //정점, 간선의 개수 
	cin >> V >> E;
	vector<vector<int>> graph(V+1, vector<int>(V+1, INF)); //길이 없는 경우 INF로 초기화
	while (E--) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from][to] = weight;
	}

	//플로이드 와샬 알고리즘. a-> b 최단 경로 갱신
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (graph[i][k] == INF || graph[k][j] == INF) continue; //길이 없는 경우 
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}

	//사이클 중 최단 경로 출력 
	int cycle = INF; //사이클 도로 길이의 합. 
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cycle = min(graph[i][j] + graph[j][i], cycle);
		}
	}
	
	cout << (cycle == INF ? -1 : cycle);

	return 0;

}
