//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
int N, M, lab[51][51], visited[51][51], answer = INF; //answer은 모든 칸에 바이러스를 퍼뜨릴 수 있는 최소시간
vector<pair<int, int>> virusPos; //바이러스 위치 리스트
int moveY[4] = {0, 0, 1, -1};
int moveX[4] = {1, -1, 0, 0};

bool isAllCheck() {
	int time = 0;
	for (int i = 0; i< N; i++) {
		for (int j = 0; j < N; j++) {
			if (lab[i][j] == 2 || lab[i][j] == -2 || lab[i][j] == 1) continue; //바이러스, 벽인 경우

			if (visited[i][j] == 0)  return false; //하나라도 퍼뜨려지지 않은 곳이 있는지 체크
			time = max(time, visited[i][j]);  //바이러스 전체 퍼뜨리는데 걸린 시간 구하기
		}
	}

	answer = min(answer, time); //answer 최솟값 갱신
	return true;
}

bool spread(vector<pair<int, int>> activeVirus) { //활성상태 바이러스 위치에서 동시에 퍼뜨리고, 전체 빈 칸에 퍼뜨릴 수 있는지 bool형으로 반환
	
	//활성상태 바이러스 위치에서 동시에 퍼뜨리기 
	queue<pair<int, int>> q; 
	for (auto v : activeVirus) 
		q.push({ v.first, v.second });

	while (!q.empty()) {
		pair<int, int> front = q.front();
		q.pop();

		//4방향 이동
		for (int j = 0; j < 4; j++) {
			pair<int, int> next = { front.first + moveY[j], front.second + moveX[j] };

			if (next.first < 0 || N <= next.first || next.second < 0 || N <= next.second) continue;	//범위 밖
			if (lab[next.first][next.second] == 1 || lab[next.first][next.second] == 2) continue; //벽, 활성상태 바이러스인 경우 
			if (visited[next.first][next.second]) continue; //이미 방문

			visited[next.first][next.second] = visited[front.first][front.second] + 1;
			q.push({ next.first, next.second });
		}
	}
	
	//모든 빈 칸에 퍼뜨릴 수 있는지 bool형 반환 
	if (isAllCheck()) return true;
	else return false;
}

int main() {

	//입력
	//freopen("input6.txt", "r", stdin); 
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) virusPos.push_back({ i, j });
		}
	}

	//바이러스 n개 중에 m개 활성상태로 설정하는 경우의 수(nCm)
	vector<int> combi(virusPos.size(), 0);
	for (int i = 0; i < M; i++)	combi[i] = 1;
	sort(combi.begin(), combi.end());
	
	bool flag = false; //어떤 경우에도 바이러스를 퍼뜨릴 수 없는 경우
	do {
		memset(visited, 0, sizeof(visited)); //초기화
		vector<pair<int, int>> activeVirus; 
		for (int i = 0; i < combi.size(); i++) {
			
			if (combi[i] == 0) //활성 : 2, 비활성 상태 : -2로 바꾸기 
				lab[virusPos[i].first][virusPos[i].second] = -2;
			
			else //활성상태 바이러스의 위치만 저장
				activeVirus.push_back({ virusPos[i].first, virusPos[i].second });
		}

		//활성바이러스 기준으로 모든 빈 칸에 바이러스 퍼뜨리기 
		if (spread(activeVirus))
			flag = true;
		
	} while (next_permutation(combi.begin(), combi.end()));


	//출력
	if (flag) cout << answer << '\n';
	else cout << -1 << '\n'; 

	return 0;
}