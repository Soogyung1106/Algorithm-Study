//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M, T, x, d, k, circles[51][51], sum, cnt;
bool erased[51][51];

int getSum() { //원판에 적힌 수의 합 구하기
	int sum = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			sum += circles[i][j];
	return sum;
}

void turnLeft(int x) { //반시계 방향 회전
	vector<int> tmp(M + 1, -1);
	for (int i = 1; i <= M; i++) {
		if (i == M) tmp[i] = circles[x][1];
		else tmp[i] = circles[x][i + 1];
	}

	for (int i = 1; i <= M; i++) circles[x][i] = tmp[i];
}

void turnRight(int x) { //시계 방향 회전
	vector<int> tmp(M + 1, -1);
	for (int i = 1; i <= M; i++) {
		if (i == 1) tmp[i] = circles[x][M];
		else tmp[i] = circles[x][i - 1];
	}

	for (int i = 1; i <= M; i++) circles[x][i] = tmp[i];
}

void turn(int x, int d, int k) {

	if (d == 0) {//시계 방향
		for (int i = 0; i < k; i++) turnRight(x);
	}
	else { //반시계 방향
		for (int i = 0; i < k; i++) turnLeft(x);
	}
}

bool isSame() {
	//초기화
	sum = cnt = 0;
	memset(erased, false, sizeof(erased)); 
	bool flag = false;
	int moveY[] = {1, 0}, moveX[] = {0, 1};
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			if (circles[i][j]) { //지워진 값이 아니라면..(나중에 평균 구하기 위해)
				sum += circles[i][j]; cnt++;
			}

			for (int k = 0; k < 2; k++) { //인접 대상
				int nextY = i + moveY[k], nextX = j + moveX[k];
				if (nextX > M) nextX %= M;
				if (nextY > N) continue;

				if (circles[i][j] == circles[nextY][nextX] && circles[i][j]) { //0이 아니고 같으면 표시 
					erased[i][j] = erased[nextY][nextX] = true;
					flag = true;
				}
			}
		}
	}

	return flag;
}

void erase() { //지우느 ㄴ함수
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			if (erased[i][j]) circles[i][j] = 0;
}

void doOperation(){ //평균과 비교해 연산하는 함수
	double average = (double)((double)sum / (double)cnt);
	for (int i = 1; i <= N; i++) {  
		for (int j = 1; j <= M; j++) {
			if (!circles[i][j]) continue;
			if (circles[i][j] > average) circles[i][j] -= 1;
			else if (circles[i][j] < average) circles[i][j] += 1;
		}
	}
}


int main() {

	//입력
	//freopen("input5.txt", "r", stdin);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			cin >> circles[i][j];

	//T번 회전
	while (T--) {
		cin >> x >> d >> k;

		//x의 배수 원판을 방향 d로 k칸만큼 회전
		for (int i = x; i <= N; i += x) turn(i, d, k);
		
		//인접한 수 중에 같은 수가 있는 경우 
		if (isSame()) erase();
		else doOperation();
	}


	//출력
	cout << getSum() << '\n'; 
	return 0;
}
