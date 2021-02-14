//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int M, N, k; //세로, 가로, 배추의 개수; 
vector<vector <int>> ground; 
vector<pair<int, int>> cabbages; //배충의 위치만 모아 놓음.
vector<vector <bool>> visited;
int earthworm; //지렁이 개수
int moved[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void dfs(pair<int, int> cabbage) {
	//i행 j열 위치부터 주변의 배추들을 탐색하고 visited true로 변경
	visited[cabbage.first][cabbage.second] = true;

	for (int i = 0; i < 4; i++) {
		pair<int, int> next = { cabbage.first + moved[i][0], cabbage.second + moved[i][1] };
		//범위 내
		if (0 <= next.first && next.first < M && 0 <= next.second && next.second < N) 
			if (ground[next.first][next.second] && !visited[next.first][next.second]) 
				dfs(next);
	}
}

int main() {
	
	//freopen("input.txt", "r", stdin);
	int T; //테스트 케이스 개수
	cin >> T;
	vector<int> answer; //각 테스트 케이스에서 필요한 지렁이 개수를 저장
	for (int i = 0; i < T; i++) {

		//입력
		cin >> M >> N >> k; //세로, 가로
		ground.resize(M, vector<int>(N, 0));
		visited.resize(M, vector<bool>(N, false));
		for (int i = 0; i < k; i++) {
			int  x, y;
			cin >> x >> y;
			ground[x][y] = 1;
			cabbages.push_back({ x, y });
		}

		//탐색
		for (auto cabbage : cabbages) { //배추가 있는 곳을 기준으로
			if (!visited[cabbage.first][cabbage.second]) {
				dfs(cabbage);
				earthworm++;
			}
		}

		answer.push_back(earthworm);

		//초기화
		earthworm = 0; ground.clear(); visited.clear(); cabbages.clear();
	}

	//출력
	for (auto e : answer)
		cout << e << endl;

	return 0;
}