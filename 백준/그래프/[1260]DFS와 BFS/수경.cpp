#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> nodes;
vector<bool> visited;
vector<int> path; //경로를 저장

void dfs(int start) {
	//start 노드부터 dfs 탐색
	visited[start] = true;
	path.push_back(start);

	for (int i = 1; i < nodes.size(); i++){
		if (nodes[start][i] && !visited[i])
			dfs(i);
	}

}

void bfs(int start) {

	queue<int> q;
	visited[start] = true;
	q.push(start);
	path.push_back(start);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 1; i < nodes.size(); i++) {
			if (nodes[front][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
				path.push_back(i);
			}
		}
	}

}

int main() {

	//Input
	int n, m, v;
	cin >> n >> m >> v; //n은 정점의 개수, m은 간선의 개수, v는 탐색 시작 정점

	nodes.resize(n + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		nodes[from][to] = true;
		nodes[to][from] = true;
	}

	//Output
	visited.resize(n + 1, false);
	dfs(v); 
	for (auto elem : path)
		cout << elem << " ";
	cout << endl;


	path.clear(); fill(visited.begin(), visited.end(), false); //path 초기화, visited 초기화 
	bfs(v); 
	for (auto elem : path)
		cout << elem << " ";

	return 0;
}

