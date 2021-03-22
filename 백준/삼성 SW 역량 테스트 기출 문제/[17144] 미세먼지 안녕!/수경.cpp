//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int MAX = 50 + 1;
int R, C, T;
vector<vector<int>> room(MAX, vector<int>(MAX)); //방
vector<vector<int>> tmp(MAX, vector<int>(MAX)); //먼지 동시 확산을 위해 확산 전 처음 먼지 양 저장
vector<tuple<int, int>> pos; //공기 청정기 위치
int moveY[4] = { 0 , 0, 1, -1 };
int moveX[4] = { 1 , -1, 0, 0 };

int sumOfDust() {
	int answer = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if(room[i][j] != -1) answer += room[i][j];
		}
	}
	return answer;
}

void spreadDust(int y, int x) {
	
	int cnt = 0;
	for (int i = 0; i < 4; i++) { //4방향
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];

		if (nextY <0 || nextY > R - 1 || nextX <0 || nextX > C - 1) continue; //범위 밖
		if (room[nextY][nextX] == -1) continue; //공기 청정기

		cnt++;
		tmp[nextY][nextX] += room[y][x] / 5; //동시확산
	}
	
	tmp[y][x] -= (room[y][x] / 5) * cnt;
}

void spread() {
	tmp = room;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			if (room[i][j] != 0 && room[i][j] != -1)
				spreadDust(i, j); //먼지 위치

	room = tmp; //먼지 다 확산 후 원본을 확산된 것으로 바꾸기.
}

void move() {

	int y, x;
	tie(y, x) = pos[0]; //반시계 방향
	vector<vector<int>> after = room;

	after[y][1] = 0; //동
	for (int i = 2; i < C; i++) after[y][i] = room[y][i - 1];
	for (int i = y - 1; i >= 0; i--) after[i][C - 1] = room[i + 1][C - 1]; //북
	for (int i = C - 2; i >= 0; i--) after[0][i] = room[0][i + 1]; //서
	for (int i = 1; i < y; i++) after[i][0] = room[i - 1][0]; //남

	tie(y, x) = pos[1]; //시계 방향
	room = after;
	
	after[y][1] = 0; //동
	for (int i = 2; i < C; i++) after[y][i] = room[y][i - 1]; //동
	for (int i = y + 1; i <= R - 1;i++) after[i][C - 1] = room[i - 1][C - 1]; //남
	for (int i = C - 2; i >= 0; i--) after[R - 1][i] = room[R - 1][i + 1]; //서
	for (int i = R - 2; i > y; i--) after[i][0] = room[i + 1][0]; //북

	room = after;
}

int main() {

	//입력
	//freopen("input6.txt", "r", stdin);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) pos.push_back({ i, j });
		}
	}
	
	//먼지 확산 및 이동
	while (T--) {
		spread();
		move();
	}

	//출력
	cout << sumOfDust()<<'\n';

	return 0;
}
