#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

int main() {
	
	//입력
	int n, m;
	cin >> n; //도시 개수
	cin >> m; //버스 개수

	//nxn 2차원
	vector<vector<int>> graph(n+1, vector<int>(n+1, INF)); //길이 없는 경우가 0으로 무한대로 초기화
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		//조건: 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다. -> 더 작은 것으로 갱신
		graph[from][to] = min(graph[from][to], cost); //방향 그래프
	}

	//플로이드와샬 알고리즘 
	for (int k = 1; k <= n; k++) { //거쳐가는 노드 
		for (int i = 1; i <= n; i++) { //출발 노드
			for (int j = 1; j <= n; j++) { //도착 노드
				if (graph[i][k] == INF || graph[k][j] == INF || i==j) continue; //더해도 INF 나옴.
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]); // a → b → c < a → c
			}
		}
	}

	//출력
	for (int i = 1; i < graph.size();i++) {
		for (int j = 1; j < graph[i].size(); j++) {
			if (graph[i][j] == INF) cout << 0 << " ";
			else cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}