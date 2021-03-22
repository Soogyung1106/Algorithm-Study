//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N, L, R;
int ground[51][51];
vector<vector<bool>> visited;
int moveY[4] = { 0, 0, 1, -1 };
int moveX[4] = { 1, -1, 0, 0 };
int answer = 0; //인구 이동 횟수

bool movePopulation(int y, int x) {

	int cnt = 1; //연합을 이루는 칸의 개수 
	int unionPeople = ground[y][x]; //연합을 이루는 인구 수
	vector<tuple<int, int>> unionPos; //유니언을 이루는 땅의 위치
	bool flag = false; //인구 이동 여부 

	queue<tuple<int, int>> q;
	q.push({y, x});
	unionPos.push_back({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		int frontY, frontX;
		tie(frontY, frontX) = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) { //인접한 땅
			int nextY = frontY + moveY[i];
			int nextX = frontX + moveX[i];

			if (nextY<0 || nextY > N - 1 || nextX<0 || nextX > N - 1) continue; //범위 밖이라면..
			if (visited[nextY][nextX]) continue; //이미 방문했다면..

			int gap = abs(ground[frontY][frontX] - ground[nextY][nextX]);
			if (gap >= L && gap <= R) {
				q.push({ nextY, nextX });
				visited[nextY][nextX] = true;
				
				cnt++; 
				unionPeople += ground[nextY][nextX];
				unionPos.push_back({ nextY, nextX }); //연합을 이루는 땅의 위치 기록
				flag = true;
			} 
		}
	}

	if (flag) { //연합이 있었다면.
		for (auto pos : unionPos)
			ground[get<0>(pos)][get<1>(pos)] = unionPeople / cnt;
		return true;
	}
	else return false;
}

int main() {
	
	//입력
	//freopen("input4.txt", "r", stdin);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> ground[i][j];

	//bfs 탐색
	while (1) {
		bool flag = false;
		visited.clear();
		visited.resize(N + 1, vector<bool>(N + 1, false));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && movePopulation(i, j)) {
					flag = true;
				}
			}
		}
		if(flag) answer++; //인구 이동 있음. 
		else break; //인구 이동 더 이상 불가능하다면..
	}
	
	//출력
	cout << answer<<'\n';

	return 0;
}
