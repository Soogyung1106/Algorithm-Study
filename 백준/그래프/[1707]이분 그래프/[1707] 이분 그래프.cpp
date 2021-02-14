#include <iostream>
#include <vector>
using namespace std;

int visited[20001] = { 0 }; //0이면 아직 방문 x, 1이 빨강, -1이 파랑
//vector<vector<int>> graph(20001);
vector<int> graph[20001];
int v, e; //정점과 간선의 개수

void dfs(int start, int color) {
	visited[start] = color; //빨강으로 칠함. 정점은 항상

	for (int i = 0; i < graph[start].size(); i++) { //start 노드에 연결된 노드 탐색
		int next = graph[start][i];
		if (visited[next] == 0) {
			dfs(next, 0-color); //정점은 빨간색(1), 정점에 연결된 같은 레벨의 정점들은 파란색(-1)으로 칠함
		}
	}
}


int main() {

	//입력
	int K;
	cin >> K;

	vector<string> answer;
	for (int i = 0; i < K; i++) {
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		//탐색(색칠하기)
		for (int i = 1; i <= v; i++) {
			if (visited[i] == 0) 
				dfs(i, 1); //정점은 빨간색으로 칠함.
		}

		//이분 그래프 판단하기
		bool isBinaryGraph = true;
		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < graph[i].size(); j++) {				
				if (visited[graph[i][j]] == visited[i]) {
					isBinaryGraph = false;
					answer.push_back("NO");
					break;
				}
			}
			if (!isBinaryGraph) break;
		}

		if (isBinaryGraph) answer.push_back("YES");

		//초기화하기 
		for (int i = 1; i <= v; i++) {
			graph[i].clear();
			visited[i] = 0;
		}
	}

	//출력
	for (auto e : answer)
		cout << e << endl;


	return 0;
}