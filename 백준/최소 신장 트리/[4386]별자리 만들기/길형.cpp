/*
[문제]
이미 연결되어 있는 정점이 존재한다. 시작점은 박선자씨, 박선자씨는 정점번호 1로 정의한다.

[입력]
첫째 줄에 우주신들의 개수(N<=1,000) 이미 연결된 신들과의 통로의 개수(M<=1,000)가 주어진다.

두 번째 줄부터 N개의 줄에는 황선자를 포함하여 우주신들의 좌표가 (0<= X<=1,000,000), (0<=Y<=1,000,000)가 주어진다. 
그 밑으로 M개의 줄에는 이미 연결된 통로가 주어진다. 번호는 위의 입력받은 좌표들의 순서라고 생각하면 된다. 좌표는 정수이다.

[출력]
첫째 줄에 만들어야 할 최소의 통로 길이를 출력하라. 출력은 소수점 둘째짜리까지 출력하여라.
*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <tuple>
#define endl "\n"
#define MAX 1001
using namespace std;

typedef pair<int, int> PAIR;
typedef tuple<double, int, int> TUPLE;

int parent[MAX];
vector<PAIR> god;
vector<TUPLE> dist;

int Find(int index)
{
	if (parent[index] == index) return index; // 부모노드일 경우
	else return parent[index] = Find(parent[index]);
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return false; // 부모 노드가 같다면 싸이클이 생기므로 건너뜀
	else
	{
		parent[a] = b; // a의 부모를 b로 지정, 트리 연결

		return true;
	}
}

double Calculate(PAIR a, PAIR b)
{
	double x = pow(b.first - a.first, 2);
	double y = pow(b.second - a.second, 2);

	return sqrt(x + y);
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	int N, M;
	cin >> N >> M;

	double answer = 0;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i; //자기 자신을 부모로 지정
	}

	god.push_back({ 0,0 });

	for (int i = 1; i <= N; i++)
	{
		int x, y;
		cin >> x >> y;
		god.push_back({ x, y });
	}

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b); // 이미 연결된 통로들 입력
	}


	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			double far = Calculate(god[i], god[j]);
			dist.push_back({ far, i, j }); // { A-B 사이의 거리, A의 index, B의 index }
		}
	}

	sort(dist.begin(), dist.end());

	// MST 계산
	for (int i = 0; i < dist.size(); i++)
	{
		double x = get<1>(dist[i]);
		double y = get<2>(dist[i]);
		double far = get<0>(dist[i]);
		if (Union(x, y)) answer += far;
	}

	cout << fixed;
	cout.precision(2);
	cout << answer << endl;

	return 0;
}
