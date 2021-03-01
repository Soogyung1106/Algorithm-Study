#include <iostream>
#include <vector>
using namespace std;

const int INF = 9876543210;
long long dp[501];
vector<pair<int, int>> edge[60001];

int main() {

	//입력
	int N, M; //정점, 간선의 개수 
	cin >> N >> M;
	while (M--) {
		int from, to, weight;
		cin >> from >> to >> weight;
		edge[from].push_back({ to, weight });
	}

	/*벨만포드 알고리*/
	dp[1] = 0; //출발 노드에서 출발노드까지 최단거리는 0
	for (int i = 2; i <= N; i++) //처음엔 경로를 알지 못하므로 무한대로 초기화
		dp[i] = INF;
		
	//모든 정점의 인접 간선에 대해 N-1번 Relaxing 갱신 작업!
	//마지막 한번은 음수 사이클 존재하는지 검사용.
	bool cycle = false;
	for (int t = 1; t <= N; t++) {
		for (int i = 1; i <= N; i++) {
			for (auto e : edge[i]) {
				int neighbor = e.first; //인접노드 
				int dist = e.second; //i와 인접노드간의 거리

				if (dp[i] == INF) continue;
				if (dp[neighbor] > dp[i] + dist){
					dp[neighbor] = dp[i] + dist;
					if (t == N) cycle = true; //N번째에도 갱신된다면 사이클 존재.
				}
			}
		}
	}
	
	//출력
	if (cycle) cout << -1<<"\n";
	else {
		for (int i = 2; i <= N;i++) { // 1번 도시에서 2~N번 도시까지 가는 최단거리 출력
			//해당 도시로 가는 경로가 없을 경우 -1출력.
			cout << (dp[i] == INF ? -1 : dp[i]) << "\n";
		}
	}

	return 0;

}