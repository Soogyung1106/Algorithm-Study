#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

vector<deque<int>> vdq(5, deque<int>(8));

void rotateRight(int number) { //시계 방향 회전 
	int back = vdq[number].back();
	vdq[number].pop_back();
	vdq[number].push_front(back);
}

void rotateLeft(int number) { //시계 반대 방향 회전 
	int front = vdq[number].front();
	vdq[number].pop_front();
	vdq[number].push_back(front);
}

void rotate(int number, int dir) {
	//number 톱니바퀴를 기준으로 dir 방향으로 회전.. 이를 통해 주변 톱니바퀴도 회전시키기.

	vector<int> directions(5, 0); //1: 시계방향, -1: 시계반대방향, 0: 같은 극이어서 이동 x 
	directions[number] = dir;
	
	//톱니바퀴 번호에 따라 탐색 방향 다름.
	if (number == 1) { //오른쪽 방향으로 비교 
		for (int i = 1; i < 4; i++) {
			if (vdq[i][2] != vdq[i + 1][6])  directions[i + 1] = 0 - directions[i]; //다른 극
			else  break; //같은 극 
		}
	}else if (number == 4) { //왼쪽 방향으로 비교
		for (int i = 4; i > 1; i--) {
			if (vdq[i][6] != vdq[i - 1][2])  directions[i - 1] = 0 - directions[i]; 
			else  break; 
		}
	}else { //왼쪽 방향으로 비교 후 오른쪽 방향으로 비교
		for (int i = number; i > 1; i--) {
			if (vdq[i][6] != vdq[i - 1][2])  directions[i - 1] = 0 - directions[i]; 
			else  break; 
		}

		for (int i = number; i < 4; i++) {
			if (vdq[i][2] != vdq[i + 1][6])  directions[i + 1] = 0 - directions[i]; 
			else  break;  
		}
	}

	//directions 순회하면서 회전하기	
	for (int i = 1; i <= 4; i++) {
		if (directions[i] == 1)
			rotateRight(i);
		else if (directions[i] == -1)
			rotateLeft(i);
	}
}

int main() {

	//입력
	for (int i = 1; i <= 4; i++) 
		for (int j = 0; j < 8; j++) 
			scanf_s("%1d", &vdq[i][j]); //톱니바퀴 상태

	int k; 
	cin >> k; //회전횟수
	while (k--) {
		int number, direction; //회전시킨 톱니바퀴 번호, 방향
		cin >> number >> direction;
		rotate(number, direction); //톱니바퀴들의 상태를 바꿔주기 
	}
	
	//출력
	int answer = 0;
	for (int i = 1; i <= 4; i++) {
		if (i == 1 && vdq[i][0] == 1) answer += 1;
		if (i == 2 && vdq[i][0] == 1) answer += 2;
		if (i == 3 && vdq[i][0] == 1) answer += 4;
		if (i == 4 && vdq[i][0] == 1) answer += 8;
	}

	cout << answer;

	return 0;
}