
/*
[문제]
상근이는 겨울방학을 맞아 N개국을 여행하면서 자아를 찾기로 마음먹었다.

하지만 상근이는 새로운 비행기를 무서워하기 때문에, 최대한 적은 종류의 비행기를 타고 국가들을 이동하려고 한다.

이번 방학 동안의 비행 스케줄이 주어졌을 때, 상근이가 가장 적은 종류의 비행기를 타고 모든 국가들을 여행할 수 있도록 도와주자.

상근이가 한 국가에서 다른 국가로 이동할 때 다른 국가를 거쳐 가도(심지어 이미 방문한 국가라도) 된다.

[입력]
첫 번째 줄에는 테스트 케이스의 수 T(T ≤ 100)가 주어지고,

각 테스트 케이스마다 다음과 같은 정보가 주어진다.

첫 번째 줄에는 국가의 수 N(2 ≤ N ≤ 1 000)과 비행기의 종류 M(1 ≤ M ≤ 10 000) 가 주어진다.
이후 M개의 줄에 a와 b 쌍들이 입력된다. a와 b를 왕복하는 비행기가 있다는 것을 의미한다. (1 ≤ a, b ≤ n; a ≠ b)
주어지는 비행 스케줄은 항상 연결 그래프를 이룬다.

[출력]
테스트 케이스마다 한 줄을 출력한다.

상근이가 모든 국가를 여행하기 위해 타야 하는 비행기 종류의 최소 개수를 출력한다.
*/

/*
[신장트리란?]
Spanning Tree란
그래프 내의 모든 정점을 포함하는 트리

Spanning Tree = 신장 트리 = 스패닝 트리
Spanning Tree는 그래프의 최소 연결 부분 그래프 이다.
최소 연결 = 간선의 수가 가장 적다.
n개의 정점을 가지는 그래프의 최소 간선의 수는 (n-1)개이고, (n-1)개의 간선으로 연결되어 있으면 필연적으로 트리 형태가 되고 이것이 바로 Spanning Tree가 된다.
즉, 그래프에서 일부 간선을 선택해서 만든 트리

[신장 트리의 조건]
본래의 그래프의 모든 노드를 포함해야 함
모든 노드가 서로 연결
트리의 속성을 만족시킴 (사이클이 존재하지 않음)

[최소 신장트리란?]
Minimum Spanning Tree, MST 라고 불리움
가능한 Spanning Tree 중에서, 간선의 가중치 합이 최소인 Spanning Tree를 지칭함

[최소 신장트리 알고리즘]
그래프에서 최소 신장 트리를 찾을 수 있는 알고리즘이 존재함
대표적인 최소 신장 트리 알고리즘
Kruskal’s algorithm (크루스칼 알고리즘)
Prim's algorithm (프림 알고리즘)

https://velog.io/@dnjscksdn98/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%B5%9C%EC%86%8C-%EC%8B%A0%EC%9E%A5-%ED%8A%B8%EB%A6%AC

https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

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
		int n, m;
		cin >> n >> m;

		while (m--)
		{
			int temp1, temp2;
			cin >> temp1 >> temp2;
		}

		cout << n - 1 << endl;
	}

	return 0;
}
