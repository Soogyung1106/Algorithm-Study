//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int N, M; //세로, 가로
int map[51][51];
int curY, curX; //로봇 청소기의 현재 위치
int dir; //로봇 청소기의 현재 방향
int moveY[4] = { -1, 0, 1, 0 };
int moveX[4] = { 0, 1, 0, -1 };
int answer = 0; //청소하는 칸의 개수

void dfs() {

	bool check = false;
	for (int i = 0; i < 4; i++) {
		dir = (dir + 3) % 4; //2. 현재 방향에서 왼쪽으로 회전

		//로봇의 현재 위치를 방향에 맞게 이동(0:북, 1:동, 2:남, 3:서)
		int nextY = curY + moveY[dir];
		int nextX = curX + moveX[dir];

		if (nextY < 0 || nextY > N - 1 || nextX < 0 || nextX > M - 1)  continue; //범위 밖

		if (map[nextY][nextX] == 0) { //2-a. 빈 공간인 경우(청소 x, 벽 x) 
			
			curY = nextY; curX = nextX;
			map[curY][curX] = 100; //1. 현재 위치를 청소
			answer++;
			dfs();
			check = true;
			break;
		}	
		//2-b. 청소할 수 없다면 2번으로 돌아감.
	}
	
	if (!check) { //2-c. 네 방향이 모두 벽
		//바라보는 방향을 유지한 채 한 칸 후진
		int tmpY = curY + moveY[(dir + 2) % 4];
		int tmpX = curX + moveX[(dir + 2) % 4];

		//2-d. 벽이라 후진도 못할 경우
		if (tmpY < 0 || tmpY > N - 1 || tmpX < 0 || tmpX > M - 1 || map[tmpY][tmpX] == 1) return;
		else {
			curY = tmpY; curX = tmpX;
			dfs();
		}
	}

}

int main() {

	//freopen("input1.txt", "r", stdin);
	cin >> N >> M;
	cin >> curY >> curX >> dir;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> map[i][j];

	//현재 위치를 청소
	map[curY][curX] = 100; 
	answer++;

	dfs(); 
	cout << answer << '\n'; 

	return 0;
}
