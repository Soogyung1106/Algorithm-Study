#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	
	//입력
	int nodes, edges;
	cin >> nodes;
	cin >> edges;

	//초기화
	vector<bool> visited(nodes + 1, false);
	vector<vector <bool>> computers(nodes+1, vector<bool>(nodes+1, false));
	for (int i = 0; i < edges; i++) {
		int from, to;
		cin >> from >> to;
		computers[from][to] = true;
		computers[to][from] = true;
	}

	//bfs로 탐색 
	int answer = 0; //1번 노드와 연결된 개수 저장.
	queue<int> q;
	q.push(1); visited[1] = true;
	
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int i = 2; i <= nodes; i++) {
			if (computers[front][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
				answer++;
			}
		}
	}

	//출력
	cout << answer;

	return 0;
}
