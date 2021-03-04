#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 100 + 1;
int nodes[MAX]; //nodes[i] : i번 노드의 조상 노드를 저장.
vector<tuple<double, int, int>> edges; //(거리, from, to)
int V; 

int Find(int x) {
	//x번 노드의 조상 노드를 찾기
	if (nodes[x] == x) return x;
	else return Find(nodes[x]);
}

void Union(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);
	nodes[rootB] = rootA; //b의 조상노드에 a의 조상노드 
}

int main() {

	//입력 
	cin >> V;//정점 개수

	vector<tuple<double, double>> coord; //좌표 (x, y)
	for(int i=0;i<V;i++){
		double x, y;
		cin >> x >> y;
		coord.push_back({ x, y });
	}

	//(거리, 출발노드, 도착노드)로 구조화
	for (int i = 0; i < coord.size(); i++) {
		for (int j = i + 1; j < coord.size(); j++) {
			double x1, y1, x2, y2;
			tie(x1, y1) = coord[i];
			tie(x2, y2) = coord[j];

			double dist= sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
			edges.push_back({ dist, i, j });
		}
	}


	/*MST 알고리즘*/

	for (int i = 0; i < V; i++) nodes[i] = i; //자기 자신으로 초기화
	
	sort(edges.begin(), edges.end()); //거리 기준 오름차순으로 정렬

	int edgeCnt = 0; //간선의 개수
	double sum = 0; //가중치 합.
	for (auto edge : edges) {
		if (edgeCnt == V - 1)
			break;

		double cost; int a, b;
		tie(cost, a, b) = edge;

		if (Find(a) != Find(b)) { //Find: 사이클이 생성되지 않는다면. = 조상이 같지 않다면 
			edgeCnt++;
			sum += cost;
			Union(a, b); //Union: 한 그래프로 만들기 = 조상 합치기
		}
	}

	cout << fixed; cout.precision(2);
	cout << sum;

	return 0;
}