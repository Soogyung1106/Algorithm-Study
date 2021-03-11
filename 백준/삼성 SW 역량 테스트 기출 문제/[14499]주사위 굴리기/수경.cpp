/* 주사위 바닥면: [3][1], 윗면: [1][1]
0 2 0
4 1 3
0 5 0
0 6 0
*/
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int dice[4][3]; //0으로 초기화 
int map[20][20];
int N, M, curX, curY, K;  //curX, curY는 주사위의 현재 위치
int moveX[5] = {0, 0, 0, -1, 1}; //1: 동, 2: 서, 3: 북, 4: 남 
int moveY[5] = {0, 1, -1, 0, 0};

bool check(int order) {

	int tmpX = curX + moveX[order]; 
	int tmpY = curY + moveY[order];

	if (tmpX<0 || tmpX>N-1 || tmpY<0 || tmpY>M-1) 
		return false;
	else {
		curX = tmpX; curY = tmpY; //범위 초과하지 않는다면 주사위 위치 갱신
		return true;
	}
}

void rollRight() {
	int tmp = dice[1][2];
	dice[1][2] = dice[1][1];
	dice[1][1] = dice[1][0];
	dice[1][0] = dice[3][1];
	dice[3][1] = tmp;
}

void rollLeft() {
	int tmp = dice[1][0];
	dice[1][0] = dice[1][1];
	dice[1][1] = dice[1][2];
	dice[1][2] = dice[3][1];
	dice[3][1] = tmp;
}

void rollDown() {
	int tmp = dice[3][1];
	dice[3][1] = dice[2][1];
	dice[2][1] = dice[1][1];
	dice[1][1] = dice[0][1];
	dice[0][1] = tmp;
}

void rollUp() {
	int tmp = dice[0][1];
	dice[0][1] = dice[1][1];
	dice[1][1] = dice[2][1];
	dice[2][1] = dice[3][1];
	dice[3][1] = tmp;
}

void rollDice(int order) {

	switch (order) {
	case 1: 
		rollRight(); //주사위에 써져있는 숫자들도 위치 바꿔주기
		break;
	case 2:
		rollLeft();
		break;
	case 3:
		rollUp();
		break;
	case 4:
		rollDown();
		break;
	}

	//지도에 써져 있는 값과 주사위의 바닥에 써져 있는 값 비교 
	if (map[curX][curY] == 0)
		map[curX][curY] = dice[3][1];
	else {
		dice[3][1] = map[curX][curY]; //지도에 쓰여 있는 수가 주사위 바닥으로 복사
		map[curX][curY] = 0; //지도는 0이 됨. 
	}

}

int main() {

	//freopen("input4.txt", "r", stdin);
	cin >> N >> M >> curX >> curY >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	while (K--) {
		int order;
		cin >> order;
		if (check(order)) { //주어진 명령이 지도 밖을 벗어나지 않는 경우
			rollDice(order); //주사위를 돌리기
			cout << dice[1][1] << '\n'; //주사위의 윗면 출력
		}
	}

	return 0;
}
