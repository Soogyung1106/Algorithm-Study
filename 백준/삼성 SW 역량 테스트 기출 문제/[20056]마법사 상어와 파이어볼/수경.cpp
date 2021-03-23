//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, M, K;
vector<tuple<int, int, int, int, int>> fireballs;
vector<tuple<int, int, int, int, int>> map[51][51];
int moveY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int moveX[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int sumOfMass() {
	int sum = 0;
	for (auto ball : fireballs) sum += get<2>(ball);
	return sum;
}

void init() {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			map[i][j].clear();	
} 

void moveBall() {
	
	init(); //map 정보 초기화

	for (auto& ball : fireballs) { 
		int& y = get<0>(ball); int& x = get<1>(ball); 
		int s = get<3>(ball), d = get<4>(ball);

		y = (y + moveY[d] * s) % N; 
		x = (x + moveX[d] * s) % N;
		if (y < 0) y += N; 
		if (x < 0) x += N;

		map[y][x].push_back(ball);
	}
}

void divideBall() {

	vector<tuple<int, int, int, int, int>> tmp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			if (map[i][j].size() >= 2) { //파이어볼 4개 분리
				int sumM = 0, sumS = 0;
				bool is_even = false, is_odd = false;
				for (auto ball : map[i][j]) {
					sumM += get<2>(ball);
					sumS += get<3>(ball);
					
					if (get<4>(ball) % 2 == 0)	is_even = true; //방향 홀짝 판단
					else is_odd = true;
				}

				if (sumM / 5 == 0) continue; //소멸
				
				int x = 0;
				if (is_even && is_odd) x = 1;

 				for (int k=0; k < 4; k++) {
					tmp.push_back({ i, j, sumM / 5, sumS / map[i][j].size(), x });
					x += 2;
				}

			}else if (map[i][j].size() == 1) 
				tmp.push_back(map[i][j][0]);
		}
	}

	fireballs = tmp; //파이어볼 분해된 것으로 업데이트
}


int main() {

	//입력
	//freopen("input4.txt", "r", stdin);
	cin >> N >> M >> K;
	while (M--) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireballs.push_back({ r,c,m,s,d });
	}

	//명령 수행
	while (K--) {
		moveBall(); //O(K*M)
		divideBall(); //O(K*N^2)
	}

	//출력
	cout << sumOfMass()<<'\n';
	return 0;
}
