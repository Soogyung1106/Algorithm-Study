#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 800 + 1;
const int INF = 1000000000;
int N, edge;
vector<pair<int, int>> graph[MAX]; // (i노드와 연결된 인접노드, 비용)

int dijkstra(int from, int to) {

	//기본적으로 연결되지 않은 경우 비용은 무한
	vector<long long> dp(N + 1, INF); //from 노드부터 i노드까지 최단 거리(비용) 저장
	dp[from] = 0; //from 노드부터 출발
	priority_queue<pair<long long, int>> pq; //최소비용이 맨 위로 오도록 힙 활용 
	pq.push({ 0, from }); //(비용, 출발노드)

	while (!pq.empty()) {

		//최소 비용의 인덱스
		long long cost = -pq.top().first; //저장할 때 cost 음수로 저장했기 때문에
		int curr = pq.top().second;		
		pq.pop();

		if (dp[curr] < cost) continue;

		//선택된 노드의 인접 노드 순회
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first; //curr 노드와 연결된 인접노드

			//인접노드에 거쳐서 갈 경우
			long long nextCost = cost + graph[curr][i].second;
			if (nextCost < dp[next]) { //기존의 최소 비용보다 더 저렴하다면 갱신 ↓
				dp[next] = nextCost;
				pq.push({ -nextCost, next }); //pq는 기본 max 힙이여서 min 힙으로 바꾸기 위해
			}
		}
	}

	return dp[to]; //from노드부터 to 노드까지의 최단거리 반환.
}


int main() {
	
	//입력
	cin >> N >> edge;
	for (int i = 0; i < edge; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({ to, weight }); //무방향이기 때문.
		graph[to].push_back({ from, weight }); 
	}

	int v1, v2;
	cin >> v1 >> v2;
	
	//다익스트라 (1 → v1 → v2 → N)
	int r1 = dijkstra(1, v1);
	int r2 = dijkstra(v1, v2);
	int r3 = dijkstra(v2, N);

	int answer = INF;
	if (r1 != INF && r2 != INF && r3 != INF)
		answer = r1 + r2 + r3;

	//다익스트라 (1 → v2 → v1 → N)
	r1 = dijkstra(1, v2);
	r2 = dijkstra(v2, v1);
	r3 = dijkstra(v1, N);

	if (r1 != INF && r2 != INF && r3 != INF)
		answer = min(answer, r1 + r2 + r3);
	
	//출력
	if (answer == INF) cout << -1;
	else cout << answer;
		
}