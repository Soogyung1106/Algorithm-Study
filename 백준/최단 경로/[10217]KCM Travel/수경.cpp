#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

typedef tuple<int, int, int> TUPLE; //자료형 재정의

#define INF 1000000000
int T, N, M, K;
int u, v, c, d;
int dp[101][10001], ans; 
vector<TUPLE> graph[101];

void init() // 초기화
{
	for (int i = 1; i <= 100; i++){
		graph[i].clear();

		for (int j = 0; j <= 10000; j++)
			dp[i][j] = INF;
	}
}

void dijkstra()
{
	priority_queue<TUPLE, vector<TUPLE>, greater<TUPLE>> pq;

	dp[1][0] = 0; //1번 노드에서 출발해 1번 노드로 도착하는데 시간(0), 비용(0) 소요
	pq.push({ 0, 1, 0 }); // 누적 시간, 출발지, 누적 비용 

	while (!pq.empty())
	{
		int time, curr, money; // 누적 시간, 현재 노드, 누적 비용 
		tie(time, curr, money) = pq.top();
		
		pq.pop();

		if (dp[curr][money] < time) continue;

		for (auto g : graph[curr]) // i : 목적지
		{
			int next_time = time + get<0>(g); // 소요 시간
			int next = get<1>(g); // 다음 공항
			int next_money = money + get<2>(g); // 소요 비용


			// 돈 초과시 갈 수 없는 경로가 되므로 pass
			if (next_money > M) continue;

			// 갱신
			if (dp[next][next_money] > next_time) {
				dp[next][next_money] = next_time;
				pq.push({ next_time, next, next_money });
			}
		
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();

	cin >> T;

	while (T--){
		init(); //매번 초기화. (전역변수 공유)

		//입력
		cin >> N >> M >> K;

		for (int i = 0; i < K; i++){
			cin >> u >> v >> c >> d; //출발지, 도착지, 비용, 시간
			graph[u].push_back({ d,v,c }); // 시간, 도착지, 비용 (맨 앞[시간]을 기준으로 min heap 구성)
		}

		//다익스트라 알고리즘
		dijkstra();
		
		//출력
		int ans = INF;
		for (int i = 1; i <= M; i++)
			ans = min(ans, dp[N][i]);

		if (ans == INF) cout << "Poor KCM" << '\n';
		else cout << ans << '\n';

	}
}
