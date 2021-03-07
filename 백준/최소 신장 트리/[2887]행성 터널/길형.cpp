/*
[문제]
때는 2040년, 이민혁은 우주에 자신만의 왕국을 만들었다. 왕국은 N개의 행성으로 이루어져 있다. 민혁이는 이 행성을 효율적으로 지배하기 위해서 행성을 연결하는 터널을 만들려고 한다.

행성은 3차원 좌표위의 한 점으로 생각하면 된다. 두 행성 A(xA, yA, zA)와 B(xB, yB, zB)를 터널로 연결할 때 드는 비용은 min(|xA-xB|, |yA-yB|, |zA-zB|)이다.

민혁이는 터널을 총 N-1개 건설해서 모든 행성이 서로 연결되게 하려고 한다. 이때, 모든 행성을 터널로 연결하는데 필요한 최소 비용을 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 행성의 개수 N이 주어진다. (1 ≤ N ≤ 100,000) 다음 N개 줄에는 각 행성의 x, y, z좌표가 주어진다. 좌표는 -109보다 크거나 같고, 109보다 작거나 같은 정수이다. 한 위치에 행성이 두 개 이상 있는 경우는 없다.

[출력]
첫째 줄에 모든 행성을 터널로 연결하는데 필요한 최소 비용을 출력한다.
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
using namespace std;

typedef pair<int, int> PAIR;
typedef tuple<long long, int, int> TUPLE;
const int MAX = 100000;

int N;
vector<int> parent;

int Find(int index)
{
	if (parent[index] == index) return index; // 부모노드일 경우
	else return parent[index] = Find(parent[index]);
}

bool Union(int a, int b) 
{
	a = Find(a);
	b = Find(b);

	if (a == b) return false;
	else if (a > b) parent[a] = b;
	else parent[b] = a;

	return true;
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
	cin >> N;

	parent.assign(N, 0);
	for (int i = 0; i < N; i++) 
	{
		parent[i] = i;
	}

	vector<PAIR> x, y, z;
	vector<TUPLE> distance;

	for (int i = 0; i < N; i++) 
	{
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a, i }); // { x좌표, index }
		y.push_back({ b, i }); // { y좌표, index }
		z.push_back({ c, i }); // { z좌표, index }
	}
	// 모든 간선의 정보를 vector배열을 이용해 넣으면 N x (N-1)개 만큼 소요됨 O(N^2)만큼 시간복잡도, 공간복잡도
	sort(x.begin(), x.end()); 
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	for (int i = 0; i < N - 1; i++) 
	{
		distance.push_back({ abs(x[i].first - x[i + 1].first), x[i].second, x[i + 1].second });
		distance.push_back({ abs(y[i].first - y[i + 1].first), y[i].second, y[i + 1].second });
		distance.push_back({ abs(z[i].first - z[i + 1].first), z[i].second, z[i + 1].second });
	}

	sort(distance.begin(), distance.end());

	int count = 0;
	long long sum = 0;

	for (int i = 0; i < distance.size() && count != N - 1; i++) // MST
	{
		if (Union(get<1>(distance[i]), get<2>(distance[i])))
		{
			count++;
			sum += get<0>(distance[i]);
		}
	}

	cout << sum << endl;

	return 0;
}
