#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000 + 1;
int nodes[MAX]; //nodes[i] : i번 노드의 조상 노드를 저장.
vector<tuple<int, int, int>> edges; //(비용, from, to)
int V, E; 

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

bool isCycle(int a, int b){
	//사이클 생성 여부 = a번 노드와 b번 노드의 조상이 같은지
	return Find(a) == Find(b);
}

int main() {

	//입력 
	cin >> V >> E; //정점, 간선의 개수
	while (E--) {
		int from, to, weight;
		cin >> from >> to >> weight;

		if (from > to) swap(from, to); //항상 from에 더 작은 번호의 노드가 오도록.
		edges.push_back({ weight, from, to });
	}

	/*MST 알고리즘*/
	//비용 기준 오름차순으로 정렬
	sort(edges.begin(), edges.end());

	//초기화
	for (int i = 1; i <= V; i++) 
		nodes[i] = i; //자기 자신으로.

	int edgeCnt = 0; //간선의 개수
	long long sum = 0; //가중치 합.
	for (auto edge : edges) {
		if (edgeCnt == E - 1)
			break;
        
		int cost, a, b;
		tie(cost, a, b) = edge;

		//Find: 사이클이 생성되지 않는다면. = 조상이 같지 않다면 
		if (!isCycle(a, b)) {
			edgeCnt++;
			sum += cost;
			Union(a, b); //Union: 한 그래프로 만들기 = 조상 합치기
		}
	}

	cout << sum;

	return 0;
}
