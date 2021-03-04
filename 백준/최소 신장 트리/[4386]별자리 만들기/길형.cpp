/*
[문제]
도현이는 우주의 신이다. 이제 도현이는 아무렇게나 널브러져 있는 n개의 별들을 이어서 별자리를 하나 만들 것이다. 별자리의 조건은 다음과 같다.

별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태이다.
모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 한다.
별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때마다 두 별 사이의 거리만큼의 비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하시오.

[입력]
첫째 줄에 별의 개수 n이 주어진다. (1 ≤ n ≤ 100)

둘째 줄부터 n개의 줄에 걸쳐 각 별의 x, y좌표가 실수 형태로 주어지며, 최대 소수점 둘째자리까지 주어진다. 좌표는 1000을 넘지 않는 양의 실수이다.

[출력]
첫째 줄에 정답을 출력한다. 절대/상대 오차는 1/100까지 허용한다.(소수점 2째짜리까지 출력)

[입력]
3
1.0 1.0
2.0 2.0
2.0 4.0

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
#define MAX 101
using namespace std;

typedef pair<double, double> PAIR;
typedef tuple<double, int, int> TUPLE;

int parent[MAX];
vector<PAIR> star;
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
	int N;
	cin >> N;

	double answer = 0;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i; //자기 자신을 부모로 지정
	}
		
	// 별들의 좌표 입력
	star.push_back({ 0,0 });

	for (int i = 1; i <= N; i++)
	{
		double x, y;
		cin >> x >> y;
		star.push_back({ x, y });
	}

	// i번째 별과 j번째 별 사이의 거리 계산
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			double far = Calculate(star[i],star[j]);
			dist.push_back({ far, i, j }); // { A-B 사이의 거리, 별 A의 index, 별 B의 index }
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
