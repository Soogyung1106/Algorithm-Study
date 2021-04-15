//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef struct {
	int num, time; //냄새를 남긴 상어의 번호, 냄새 남은 시간.
}SMELL;

typedef struct {
	int y, x, dir; //상어의 현재 위치, 방향 (냄새는 k초로 초기화)
}SHARK;

typedef struct dirPriority{ 
	int dir[5][4]; //방향에 따른 방향 우선순위
}PRIORITY;

int N, M, k;
vector< vector<SMELL>> map(21, vector<SMELL>(21));
vector<PRIORITY> priority(401); //상어의 번호에 따른 방향 우선순위 (상어가 없을 경우 num, time은 0)
vector<SHARK> sharkInfo(401); //상어들의 정보를 따로 모아놓는 리스트 ??(해당 번호의 상어가 없을 경우 방향은 0)
vector<int> sharkAlive; //살아있는 상어들 번호만 모아놓은 리스트
int moveY[5] = { 0, -1, 1, 0, 0};  //1, 2, 3, 4는 각각 위, 아래, 왼쪽, 오른쪽
int moveX[5] = { 0, 0, 0, -1, 1};


vector< vector<SMELL>> reduceTime(vector< vector<SMELL>> tmp){
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			if(tmp[i][j].num != 0)  tmp[i][j].time -= 1; //시간 감소.
			
			if (tmp[i][j].time == 0)  tmp[i][j].num = 0; //num도 0으로 상어 흔적 지워주기
		}
	}

	return tmp;
	
}

void deleteSharkList(vector<int> sharkDead){
	for (auto n : sharkDead){
		for (int i = 0; i < sharkAlive.size(); i++) {
			if (n == sharkAlive[i]) {
				sharkAlive.erase(sharkAlive.begin() + i);
				i--;
			}
		}
	}
}

void moveSharks() {
	
	
	vector< vector<SMELL>> tmp; //상어들을 동시에 이동시키기 위해 원본 map 복사 후
	tmp = map; //tmp에다 변화시키기.

	vector<int> sharkDead; //이동하면서 제거된 상어 리스트

	//1. 이동 전에 전체 냄새의 시간 감소 시키기. 
	tmp = reduceTime(tmp);

	//2. num번호 상어를 이동.
	for (auto num : sharkAlive) {
		
		//3. 후보 중 이동할 칸 선정하기
		vector<tuple<int, int, int>> noSmell, mySmell; //'냄새 없는 칸들', '자기 자신 냄새 나는 칸들' (y, x, d) 저장.
		int curDir = sharkInfo[num].dir; //상어의 현재 방향.
		int nextY, nextX, nextDir; //상어가 이동할 다음 위치와 바뀐 방향

		for (int j = 0; j < 4; j++) { //우선순위 방향에 따른 상하좌우 순회
			int d = priority[num].dir[curDir][j];  
			int nextY = sharkInfo[num].y + moveY[d], nextX = sharkInfo[num].x + moveX[d];

			if (nextY <0 || nextY > N - 1 || nextX <0 || nextX > N - 1) continue; //범위 초과

			//a. 냄새 없는 칸 후보 저장
			if (map[nextY][nextX].time == 0) noSmell.push_back({ nextY, nextX, d }); 
			//b. 자신의 냄새 칸 후보 저장
			if(map[nextY][nextX].time != 0 && map[nextY][nextX].num == num) mySmell.push_back({ nextY, nextX, d });
		}

		if (!noSmell.empty()) tie(nextY, nextX, nextDir) = noSmell.front();  //a. 리스트 중 고르기
		else  tie(nextY, nextX, nextDir) = mySmell.front(); //b. 리스트 중 고르기
	

		//4. 선정된 위치로 이동하면서 제거하기
		int time = tmp[nextY][nextX].time, exist = tmp[nextY][nextX].num;
		if (time == k) { //이미 다른 상어가 있다면.. 
			
			if (exist < num) { //num 상어 제거
				sharkInfo[num] = { 0, 0, 0 };
				sharkDead.push_back(num); //제거된 상어 리스트에도 추가 
			}
			else { //exist 상어 제거하기
				sharkInfo[exist] = { 0, 0, 0 }; 
				sharkDead.push_back(exist);

				//num으로 갱신.
				tmp[nextY][nextX] = { num, k };
				sharkInfo[num] = { nextY, nextX, nextDir };
			}
		}
		else { 
			tmp[nextY][nextX] = { num, k };
			sharkInfo[num] = { nextY, nextX, nextDir }; //num 상어의 방향, 위치 바꿔주기
		}

	}
	
	//5. 이동 후 tmp를 map에 복사하기
	map = tmp;

	//sharkAlive 리스트 에서도 상어 제거하기. 
	if(!sharkDead.empty()) deleteSharkList(sharkDead);
	
}

int main() {

	//입력
	//freopen("input5.txt", "r", stdin);
	cin >> N >> M >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int shark; 
			cin >> shark; //상어 

			if (shark == 0) {//상어가 없는 경우
				map[i][j] = { 0, 0 }; //num = time = 0 으로 초기화
				continue;
			}  

			sharkAlive.push_back(shark); //상어의 번호 리스트에 추가.
			sharkInfo[shark] = { i, j, 0 }; //상어 정보 초기화 (y, x, dir) 		
			map[i][j] = { shark, k }; //냄새 정보 맵에 저장 (num, time)
		}
	}

	for (int i = 1; i <= M; i++) cin >> sharkInfo[i].dir; //상어의 초기 방향

	for(int i=1;i<=M;i++) //M마리 상어
		for (int j = 1; j <= 4; j++) 
			for (int k = 0; k < 4; k++) 
				cin >> priority[i].dir[j][k]; //방향 우선순위


	//계산
	int time = 0;
	while (1) {
		if (time >= 1000) { //1000초가 넘어도..
			if (sharkAlive.size() >= 2) {
				cout << -1 << '\n';
				break;
			} 
		}

		if (sharkAlive.size() == 1) { //상어의 개수가 1개(1번 상어)일 경우
			cout << time << '\n'; 
			break;
		}

		time++; //1초 소요.
		moveSharks(); //상어들 동시에 1칸 이동. (이동하는 순간,, 냄새가 있는 칸도 1초씩 줄어듬.)
	}

	return 0;
}
