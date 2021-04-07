//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N, sand[500][500], outOfSand; //격자 밖의 모래 양
int dirY[4] = { 0, 1, 0, -1 };//좌, 하, 우, 상 순서로 이동
int dirX[4] = { -1, 0, 1, 0};
int moveY[4][10] = {
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{-1,-1,0,0,0,0,1,1,2,1},
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{1,1,0,0,0,0,-1,-1,-2,-1}
};
int moveX[4][10] = {
	{1,1,0,0,0,0,-1,-1,-2,-1},
	{-1,1,-2,-1,1,2,-1,1,0,0},
	{-1,-1,0,0,0,0,1,1,2,1},
	{-1,1,-2,-1,1,2,-1,1,0,0}
};
int percent[9] = { 1,1,2,7,7,2,10,10,5 }; 

void moveSand(int tornadoY, int tornadoX, int dir) { //토네이도가 이동한 위치를 기준으로 dir 방향으로 겪자의 모래들 이동

	int sum = 0, add = 0; //모래가 이동한 누적 양, 추가할 양.

	for (int i = 0; i < 10; i++) {
		//추가할 위치
		int curY = tornadoY + moveY[dir][i], curX = tornadoX + moveX[dir][i];

		//추가할 양
		if (i == 9)	add = sand[tornadoY][tornadoX] - sum;
		else add = (int)(sand[tornadoY][tornadoX] * percent[i] / 100);

		//추가
		if (curY <1 || curY>N || curX<1 || curX > N) outOfSand += add;
		else sand[curY][curX] += add;
		
		sum += add;
	}

	sand[tornadoY][tornadoX] = 0; // 이동 끝
}

int main() {

	//입력
	//freopen("input6.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> sand[i][j];
		}
	}

	//토네이도 이동
	int tornadoY = (N + 1) / 2, tornadoX = (N + 1) / 2; //토네이도의 현위치
	int dir = 0; 
	for (double i = 1.0; i <= N; i += 0.5) { //i = 1, 1.5, 2, 2.5, 3, 3.5, 4...
		for (int j = 0; j < (int)i; j++) { //for문 -> 1회, 1회, 2회, 2회, 3회, 3회...
			dir = dir % 4;
			tornadoY += dirY[dir];
			tornadoX += dirX[dir];

			moveSand(tornadoY, tornadoX, dir); //토네이도가 이동한 위치를 기준으로 dir 방향으로 겪자의 모래들 이동
		}
		dir++;
	}


	//정답 출력
	cout << outOfSand<<'\n';

	return 0;
}
