#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 20000 + 1;
const int INF = 1000000000;
int vertex, edge, start;
vector<pair<int, int>> graph[MAX]; // (i노드와 연결된 인접노드, 비용)
vector<int> dp; //start부터 i노드까지 최단 거리(비용) 저장

void dijkstra() {

	dp[start] = 0; 
	priority_queue<pair<int, int>> pq; //최소비용이 맨 위로 오도록 힙 활용 
	pq.push({ 0, start }); //(비용, 출발노드)

	while (!pq.empty()) {

		//최소 비용의 인덱스
		int cost = -pq.top().first; //저장할 때 cost 음수로 저장했기 때문에
		int curr = pq.top().second;		
		pq.pop();

		if (dp[curr] < cost) continue;

		//선택된 노드의 인접 노드 순회
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first; //curr 노드와 연결된 인접노드

			//인접노드에 거쳐서 갈 경우
			int nextCost = cost + graph[curr][i].second;
			if (nextCost < dp[next]) { //기존의 최소 비용보다 더 저렴하다면 갱신 ↓
				dp[next] = nextCost;
				pq.push({ -nextCost, next }); //pq는 기본 max 힙이여서 min 힙으로 바꾸기 위해
			}
		}
	}
}


int main() {
	
	//입력
	cin >> vertex >> edge;
	cin >> start;

	dp.resize(vertex+1, INF); //기본적으로 연결되지 않은 경우 비용은 무한

	for (int i = 0; i < edge; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({ to, weight });
	}
	
	//다익스트라 호출
	dijkstra();

	//출력
	for (int i = 1; i <= vertex; i++) {
		if (dp[i] == INF) cout << "INF" << "\n";
		else cout << dp[i] << "\n";
	}
		
}