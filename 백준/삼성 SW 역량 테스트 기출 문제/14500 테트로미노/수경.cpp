//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<vector<tuple<int, int>>> tetromino = { 
	{{0,0}, {0, 1}, {0, 2}, {0, 3}}, //1
	{{0,0}, {1, 0}, {2, 0}, {3, 0}}, //2
	{{0,0}, {0, 1}, {1, 0}, {1, 1}}, //3 
	{{0,0}, {1, 0}, {2, 0}, {2, 1}}, //4
	{{0, 1}, {1, 1}, {2, 1}, {2, 0}}, //5
	{{0,2}, {1, 0}, {1, 1}, {1, 2}}, //6
	{{0,0}, {0, 1}, {0, 2}, {1, 2}}, //7
	{{0,0}, {0, 1}, {1, 1}, {2, 1}}, //8
	{{0,0}, {0, 1}, {1, 0}, {2, 0}}, //9
	{{0,0}, {0, 1}, {0, 2}, {1, 0}}, //10
	{{0,0}, {1, 0}, {1, 1}, {1, 2}}, //11
	{{0,0}, {0, 1}, {0, 2}, {1, 1}}, //12
	{{0,0}, {1, 0}, {2, 0}, {1, 1}}, //13
	{{0,1}, {1, 0}, {1, 1}, {1, 2}}, //14
	{{0,1}, {1, 1}, {2, 1}, {1, 0}}, //15
	{{0,0}, {1, 0}, {1, 1}, {2, 1}}, //16
	{{0,1}, {0, 2}, {1, 0}, {1, 1}}, //17
	{{0,1}, {1, 0}, {1, 1}, {2, 0}}, //18
	{{0,0}, {0, 1}, {1, 1}, {1, 2}}, //19
};

int board[500][500];

int main() {

	
	//freopen("input3.txt", "r", stdin);
  //입력
	int N, M;
	cin >> N >> M; //세로 N, 가로 M
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> board[i][j];
  
  //탐색
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 19; k++) {

				//모든 tetromino의 y좌표는 i만큼, x좌표 j만큼 이동 
				vector<tuple<int, int>> tmp;
				for (auto elem : tetromino[k])   
					tmp.push_back({ get<0>(elem) + i, get<1>(elem) + j });
			
				//움직인 tetromino의 인덱스가 보드 범위 안에 있는지 검사.
				bool range = true; int sum = 0;
				for (auto elem : tmp) {
					sum += board[get<0>(elem)][get<1>(elem)];
					if (get<0>(elem) < 0 || get<0>(elem) > N - 1 || get<1>(elem) < 0 || get<1>(elem) > M - 1)
						range = false;
				}

				//범위에 있다면 합을 더 큰 것으로 갱신. 
				if (range) answer = max(answer, sum);
			}			
		}
	}
  
  //출력
	cout << answer << '\n';

	return 0;
}
