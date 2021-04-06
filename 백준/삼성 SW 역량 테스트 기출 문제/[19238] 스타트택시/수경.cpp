//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;

struct compare {
	bool operator()(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
		if (get<3>(a) == get<3>(b)) { //거리가 같다면
			if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b); //행이 같다면
			else return get<0>(a) > get<0>(b);
		}
		else return  get<3>(a) > get<3>(b);
	}
};
int N, M, energy, taxiY, taxiX; //energy: 연료, taxiY, taxiX : 현재 택시의 위치 행, 열
int road[21][21];

int getShortestDist(int destiY, int destiX) {
	//출발위치 taxiY, taxiX 에서 도착위치 destiY, dstiX까지의 최단거리를 bfs로 탐색  

	int moveY[4] = { 0, 0, 1, -1 }, moveX[4] = { 1, -1, 0, 0 };
	int visited[21][21]; 
	memset(visited, -1, sizeof(visited)); //방문 안 한 곳은 -1

	queue <tuple<int, int>> q;
	q.push({ taxiY, taxiX });
	visited[taxiY][taxiX] = 0;

	while(!q.empty()) {
		int frontY, frontX;
		tie(frontY, frontX) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = frontY + moveY[i], nextX = frontX + moveX[i]; 

			if (nextY <1 || nextY > N || nextX <1 || nextX > N) continue; //범위 밖
			if (visited[nextY][nextX] != -1 || road[nextY][nextX] == 1) continue; //이미 방문 혹은 벽
			
			visited[nextY][nextX] = visited[frontY][frontX] + 1;
			if (nextY == destiY && nextX == destiX) break;
			else q.push({ nextY, nextX });
		}
	}

	return visited[destiY][destiX];
}

int main() {

	//입력
	//freopen("input1.txt", "r", stdin);
	cin >> N >> M >> energy;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> road[i][j];
	
	cin >> taxiY >> taxiX;

	vector<tuple<int, int, int, int>> passengers; //승객의 출발 위치 y, x 도착 위치 y, x
	while (M--) {
		int startY, startX, destiY, destiX;
		cin >> startY >> startX >> destiY >> destiX;
		passengers.push_back({ startY, startX, destiY, destiX });
 	}

	//탐색
	while (!passengers.empty()) {

		//택시의 현 위치에서 승객 위치까지 최단거리 구하기
		priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, compare> dist; //승객의 출발위치 y, x, 인덱스, 최단거리

		for (int i = 0; i < passengers.size(); i++) {
			int startY = get<0>(passengers[i]), startX = get<1>(passengers[i]);
			dist.push({ startY, startX, i, getShortestDist(startY, startX) }); 
		}
		
		//제일 가까운 승객 위치로 이동하기 
		int startY, startX, idx, shortestDist;
		tie(startY, startX, idx, shortestDist) = dist.top();
		taxiY = startY, taxiX = startX;

		//연료 소모 
		if (energy - shortestDist <= 0 || shortestDist == -1) {
			energy = -1; 
			break;
		}
		else energy -= shortestDist;
		

		//선택한 승객의 목적지로 이동하기
		shortestDist = getShortestDist(get<2>(passengers[idx]), get<3>(passengers[idx]));
		taxiY = get<2>(passengers[idx]), taxiX = get<3>(passengers[idx]);

		//연료 소모
		if(energy - shortestDist < 0 || shortestDist == -1) {
			energy = -1;
			break;
		}
		else energy = energy - shortestDist + shortestDist * 2;


		//목적지에 도착한 승객은 리스트에서 삭제
		passengers.erase(passengers.begin()+idx);
	}
	
	//정답 출력
	cout << energy << '\n';

	return 0;
}
