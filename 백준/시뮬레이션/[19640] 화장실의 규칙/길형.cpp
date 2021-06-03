#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#define endl "\n"

using namespace std;

typedef struct INFO {
	int d; // 근무 일수
	int h; // 급한 정도
	int i; // 원래 줄 순서
	int line;
}INFO;

struct compare {
	bool operator()(INFO a, INFO b)
	{
		if (a.d == b.d)
		{
			if (a.h == b.h)
			{
				return a.line > b.line;
			}
			else return a.h < b.h;
		}
		else
		{
			return a.d < b.d;
		}
	}
};

int N, M, K;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> N >> M >> K;

	priority_queue<INFO, vector<INFO>, compare> order;
	vector<queue<INFO>> v(M);
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		int D, H, L;
		cin >> D >> H;

		L = i % M;
		
		v[L].push({D,H,i,L});
	}

	for (int i = 0; i < M; i++) // 가장 앞줄 채우기
	{
		if (!v[i].empty())
		{
			order.push(v[i].front());
			v[i].pop();
		}
	}

	while (order.top().i != K)
	{
		/*cout << order.top().d << " " << order.top().h << " " << order.top().i << " " << order.top().line << endl;*/
		int idx = order.top().line;
		order.pop();
		cnt++;

		if (!v[idx].empty())
		{
			order.push(v[idx].front());
			v[idx].pop();
		}
	}

	cout << cnt << endl;

	return 0;
}
