#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <tuple>
#include <queue>
#include <functional>
#define endl "\n"
#define N_MAX 103
#define M_MAX 10003
#define INF 987654321
using namespace std;

typedef tuple<int, int, int> TUPLE;

int dp[N_MAX][M_MAX]; // dp[i][j] : start 도시에서 i번 도시까지 비용 j를 써서 갈 때 최소 시간

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();

	int T;
	cin >> T;

	while (T--)
	{
		int N, M, K;
		cin >> N >> M >> K;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				dp[i][j] = INF;
			}
		}

		dp[1][0] = 0;

		vector<TUPLE> info[N_MAX]; // info[시작도시] = {도착도시의 Index, 비용, 소요시간}

		while (K--)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			info[u].push_back({ v, c, d });
		}

		priority_queue<TUPLE, vector<TUPLE>, greater<TUPLE> > pq; // 시간 도착지 비용

		pq.push({ 0, 1,0 });

		bool ExistsPath = false;

		while (!pq.empty())
		{
			auto cur = pq.top();
			pq.pop();

			int time = get<0>(cur);
			int city = get<1>(cur);
			int cost = get<2>(cur);

			if (city == N)
			{
				cout << time << endl; // 주어진 cost 내에서 time이 작은 순으로 보고있기 때문에 N에 도달하는 즉시 출력하면 됨
				ExistsPath = true;
				break;
			}

			if (dp[city][cost] < time) // 이미 city에 cost를 써서 더 빨리 도달한 경우가 있을 경우
				continue;

			for (auto near : info[city])
			{
				int city_near = get<0>(near);
				int cost_near = get<1>(near);
				int time_near = get<2>(near);

				if (cost + cost_near > M) // 예산을 초과했을 경우
					continue;

				if (dp[city_near][cost + cost_near] > time_near + time) // 더 좋은 경로를 찾은 경우
				{
					dp[city_near][cost + cost_near] = time_near + time;
					pq.push({ time_near + time , city_near, cost + cost_near });
				}
			}
		}

		if (!ExistsPath)
		{
			cout << "Poor KCM" << endl;
		}
	}

	return 0;
}
