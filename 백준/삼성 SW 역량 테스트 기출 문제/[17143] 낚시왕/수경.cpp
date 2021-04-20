//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct {
	int y, x, s, d, z;
}SHARK;
const int MAX = 10000 + 1;
int R, C, M, answer; //answer: 낚시왕이 잡은 상어 크기의 합.
vector<SHARK> sharks(MAX);
int map[101][101];  //0이면 상어가 없음.
bool isAlive[MAX]; //인덱스는 상어의 사이즈(번호), true이면 살아있음.
int moveY[5] = { 0, -1, 1, 0, 0 };
int moveX[5] = { 0, 0, 0, 1, -1 };

void fishing(int col) {
	for (int i = 1; i <= R; i++) {
		int shark = map[i][col];
		if (shark) {
			answer += shark; //상어를 잡음.
			map[i][col] = 0; isAlive[shark] = false; //상어가 사라진 것 표시.
			break;
		}
	}
}

void moveShark() {

	int tmp[101][101];
	memset(tmp, 0, sizeof(tmp)); //이동 시킬 곳.

	for (int i = 1; i < MAX; i++) {
		if (!isAlive[i]) continue; //죽었으면 스킵.

		int shark = i; //상어의 사이즈이자 식별번호.
		int y = sharks[shark].y, x = sharks[shark].x, d = sharks[shark].d, s = sharks[shark].s;

		//shark를 s칸 dir방향으로 이동. 
		for (int j = 0; j < s; j++) {
			//범위를 넘어설 경우 -> 방향 틀어서 move시키기.
			if (y + moveY[d] < 1) d = 2;
			if (R < y + moveY[d]) d = 1;
			if (x + moveX[d] < 1) d = 3;
			if (C < x + moveX[d]) d = 4;

			y += moveY[d]; x += moveX[d];
		}

		//이미 해당 위치에 상어가 있다면 크기 비교 후 죽이기 
		if (tmp[y][x]) {

			if (tmp[y][x] > shark)  //shark를 죽이기 
				isAlive[shark] = false;

			else { //tmp[y][x]에 있는 상어를 죽이기
				isAlive[tmp[y][x]] = false;

				//이동 후 바뀐 상어의 위치, 방향 tmp와 shark 리스트에 업뎃.
				tmp[y][x] = shark;
				sharks[shark].y = y, sharks[shark].x = x;
				sharks[shark].d = d;
			}
		}
		else {
			tmp[y][x] = shark;
			sharks[shark].y = y, sharks[shark].x = x;
			sharks[shark].d = d;
		}

	}

	//상어들 모두 이동 후 변화 (후)를 변화 (전)으로 복사
	memcpy(map, tmp, sizeof(tmp));
}

int main() {

	//freopen("input4.txt", "r", stdin);
	cin >> R >> C >> M;
	while (M--) {
		int y, x, s, d, z;
		cin >> y >> x >> s >> d >> z;
		if (d == 1 || d == 2) s %= ((R - 1) * 2);  
		if (d == 3 || d == 4) s %= ((C - 1) * 2); 

		map[y][x] = z;
		sharks[z] = { y, x, s, d, z };
		isAlive[z] = true;
	}

	for (int i = 1; i <= C; i++) { //(1) 낚시왕이 열(세로) 이동

		fishing(i); //(2) 땅과 가장 가까운 상어 잡기 
		moveShark(); //(3) 상어가 이동
	}

	cout << answer << '\n';

	return 0;
}
