//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
using namespace std;

typedef struct {
	int y, x, d; //체스판 말의 위치, 방향
}HORSE;

int N, K;
deque<int> board[13][13]; //보드 위에있는 말의 번호
int color[13][13]; //보드의 색
HORSE horses[11];
int moveY[5] = { 0, 0, 0, -1, 1 };
int moveX[5] = { 0, 1, -1, 0, 0 };


bool checkEnd(int horse) {
	return board[horses[horse].y][horses[horse].x].size() >= 4;
}

deque<int> popHorse(int y, int x, int horse) {
	deque<int> tmp;
	while (1) {
		int back = board[y][x].back(); //뒤에서부터 접근 

		tmp.push_back(back);
		board[y][x].pop_back();

		if (back == horse) break;
	}

	return tmp;
}

int changeDir(int horse) {
	int& dir = horses[horse].d;
	if (dir == 1) dir = 2;
	else if (dir == 2) dir = 1;
	else if (dir == 3) dir = 4;
	else dir = 3;
	return dir;
}

void pushBack(int nY, int nX, deque<int> tmp) {
	while (!tmp.empty()) { //뒤에서부터 넣기
		int back = tmp.back();
		board[nY][nX].push_back(back);
		tmp.pop_back();

		horses[back].y = nY, horses[back].x = nX; //정보 업데이트.
	}
}

void pushFront(int nY, int nX, deque<int> tmp) {
	while (!tmp.empty()) { //앞에서부터 넣기
		int front = tmp.front();
		board[nY][nX].push_back(front);
		tmp.pop_front();

		horses[front].y = nY, horses[front].x = nX;
	}
}

void moveHorse(int horse) {

	int y = horses[horse].y, x = horses[horse].x, d = horses[horse].d;

	//1. 이동하려고 하는 칸의 색부터 확인
	int nY = y + moveY[d], nX = x + moveX[d];
	deque<int> tmp;

	if (nY <1 || nY > N || nX <1 || nX>N || color[nY][nX] == 2) { //범위 밖 = 파 
		//a. 방향 반대로
		d = changeDir(horse); //바뀐 방향 반환.
		nY = y + moveY[d], nX = x + moveX[d];

		//이동하려는 칸이 또 파란색.. 이동x.
		bool canMove = true;
		if (nY <1 || nY > N || nX <1 || nX>N || color[nY][nX] == 2) 
			canMove = false;

		if (canMove) {
			if (color[nY][nX] == 1) { //빨
				tmp = popHorse(y, x, horse);
				pushFront(nY, nX, tmp); //앞에서부터
			}
			else if (color[nY][nX] == 0) { //흰
				tmp = popHorse(y, x, horse);
				pushBack(nY, nX, tmp); //뒤에서부터
			}
		}
	}
	else if (color[nY][nX] == 0) { //흰
		tmp = popHorse(y, x, horse);
		pushBack(nY, nX, tmp); //뒤에서부터
	}
	else { //빨
		tmp = popHorse(y, x, horse);
		pushFront(nY, nX, tmp); //앞에서부터
	}
	
}

int main() {

	//입력
	//freopen("input4.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> color[i][j];
		}
	}

	for (int i = 1; i <= K; i++) {
		int y, x, d;
		cin >> y >> x >> d;
		board[y][x].push_back(i); //말의 번호
		horses[i] = { y, x, d}; //말의 위치, 방향
	}

	//턴 시작.
	int turn = 1;
	while (1) {
		if (turn > 1000) { //종료
			cout << -1 << '\n';
			break;
		}

		//1번~K번 순서대로 이동.
		bool gameEnd = false;
		for (int i = 1; i <= K; i++) {
			moveHorse(i); //(1) i번 말을 이동
			if (checkEnd(i)) { //(2) i번 말이 이동한 곳에 4개 이상 쌓이는지 확인 
				gameEnd = true;
				break;
			}
		}

		if (gameEnd) { //종료
			cout << turn << '\n';
			break;
		} 
		
		turn++;
	}
	
	return 0;
}
