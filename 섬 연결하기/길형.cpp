#include <string>
#include <vector>
#include <algorithm>
/*
Kruskal(크루스칼) 알고리즘 사용


!문제 접근 방법
가장 적은 비용의 cost를 순으로 정렬, 다녀온 곳을 DP 방식으로 기록하여 최소 비용으로 다리를 건설-> 모든 섬이 연결되어 있다면 종료

==> DP방식이 아니라 크루스칼 MST(최소신장트리)를 이용하면 가장 적은 weight를 따라가며 경로를 구할 수 있음 => 어떻게 보면 greedy와 비슷

sort(costs.begin(), costs.end(), compare) -> sort 함수는 사용자 정의 함수로 정렬 할 수 있음.
*/

int parent[101]; // 현재 노드의 부모노드를 저장하는 배열

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int find_parent(int node) // 재귀함수를 사용안하고 연결리스트를 사용했으면 while(next != NULL)로 했을 수 있을 것 같음.
{
    if(parent[node] == node) return node;
    else return parent[node] = find_parent(parent[node]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for(int i = 0 ; i < n ; i++)
        parent[i] = i; // 처음에는 자기 자신을 가르키도록 초기화

    sort(costs.begin(), costs.end(), cmp);

    for(int i = 0 ; i < costs.size() ; i++)
    {
        int now = find_parent(costs[i][0]);
        int next = find_parent(costs[i][1]);

        if(now != next)
        {
            answer += costs[i][2];
            parent[next] = now; // 연결된 다리를 현재로 옮겨서 계속 costs를 탐색
        }
    }

    return answer;
}
