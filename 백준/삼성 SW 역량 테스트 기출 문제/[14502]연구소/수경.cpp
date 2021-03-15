//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> map(9, vector<int>(9));
vector<vector<int>> tmp; //벽 3개를 세우는 각 경우의 수에 대해 바이러스를 퍼뜨렸을 때의 상태
vector<tuple<int, int>> blank; //빈 칸의 위치 저장
vector<tuple<int, int>> virus; //바이러스의 위치 저장
int moveY[4] = { 1 ,-1, 0, 0 };
int moveX[4] = { 0 , 0, 1, -1};

void bfs() {
	tmp = map;

	for (auto v : virus) {
		queue<tuple<int, int>> q;
		q.push(v);

		while (!q.empty()) {
			tuple<int, int> front = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nextY = get<0>(front) + moveY[i]; 
				int nextX = get<1>(front) + moveX[i];

				if (nextY < 0 || nextY > N - 1 || nextX <0 || nextX > M - 1) continue;
				if (tmp[nextY][nextX] == 0) {
					tmp[nextY][nextX] = 2;
					q.push({ nextY, nextX });
				} 
			}
		}
	}

}

int check() {
	int cnt = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			if (tmp[i][j] == 0) cnt++; 

	return cnt;
}

int main() {
	
	//freopen("input3.txt", "r", stdin);

	//입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			//빈칸과 바이러스의 위치는 리스트에 담아두기
			if (map[i][j] == 0) blank.push_back({ i, j }); 
			else if (map[i][j] == 2) virus.push_back({ i, j }); 
		}
	}

	//벽 3개를 세우는 모든 경우의 수
	int answer = 0;
	for (int i = 0; i < blank.size();i++) {
		for (int j = i + 1; j < blank.size(); j++) {
			for (int k = j + 1; k < blank.size(); k++) {

				map[get<0>(blank[i])][get<1>(blank[i])] = 1;
				map[get<0>(blank[j])][get<1>(blank[j])] = 1;
				map[get<0>(blank[k])][get<1>(blank[k])] = 1;

				//바이러스 퍼뜨리기 
				bfs();

				//안전구역 개수 세서 최대값으로 갱신  
				answer = max(answer, check());

				//다음 경우의 수를 위해 초기화
				map[get<0>(blank[i])][get<1>(blank[i])] = 0;
				map[get<0>(blank[j])][get<1>(blank[j])] = 0;
				map[get<0>(blank[k])][get<1>(blank[k])] = 0;
			}
		}
	}

	//출력
	cout << answer<<'\n';

	return 0;
}
