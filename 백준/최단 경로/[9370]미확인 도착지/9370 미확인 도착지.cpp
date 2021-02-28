#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2000 + 1;
const int INF = 1000000000;
int N, edge, T, t, start, g, h, candi; 
vector<pair<int, int>> graph[MAX]; // (i노드와 연결된 인접노드, 비용)

long long dijkstra(int from, int to) {

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
	cin >> T; //테스트 케이스 개수
	
	for (int i = 0; i < T; i++) {
		cin >> N >> edge >> t;
		cin >> start >> g >> h;

		//초기화
		for (int i = 1; i <= N; i++) graph[i].clear(); 

		//edge개의 간선
		int gToh = 0;
		for (int i = 0; i < edge; i++) {
			int from, to, weight;
			cin >> from >> to >> weight;

			graph[from].push_back({ to, weight }); //양방향
			graph[to].push_back({ from, weight });

			if ((g == from && h == to) || (g == to && h == from))
				gToh = weight;

		}

		vector<int> desti; //확실한 목적지
		for (int i = 0; i < t; i++) {
			
			cin >> candi; //목적지 후보
			
			//start ~ candi까지의 최단경로에 g~h가 포함되어 있다면 candi 후보는 확실한 목적지 맞음.
			long long res1 = dijkstra(start, g) + gToh + dijkstra(h, candi);
			long long res2 = dijkstra(start, h) + gToh + dijkstra(g, candi);
			long long res3 = dijkstra(start, candi);
			
			if (res3 == res1) desti.push_back(candi);
			else if(res3 == res2) desti.push_back(candi);
			
		}

		sort(desti.begin(), desti.end()); //목적지 번호순 오름차순
		
		for (auto d : desti)
			cout << d << " ";
		
		cout << "\n";
		
		
	}//end for T
	
}