#include <queue>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int M, N, H; //열, 행, 높이
int tomatoes[101][101][101] = { 0 };
bool visited[101][101][101] = { false };
queue<tuple<int, int, int, int>> q; //행, 열, 높이, 익는데 소요된 날짜
vector<vector<int>> moved = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} };
int answer = 0; //다 익는데 소요된 날짜. 

void bfs() {

	while (!q.empty()) {
		
		int frow, fcol, fh, fday;
		tie(frow, fcol, fh, fday) = q.front();
		visited[frow][fcol][fh] = true;
		q.pop();

		for (auto mv : moved) {
			int nrow = frow + mv[0]; int ncol = fcol + mv[1]; int nh = fh + mv[2];
			if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M && 0 <= nh && nh < H) {
				if (tomatoes[nrow][ncol][nh] == 0 && !visited[nrow][ncol][nh]) {
					visited[nrow][ncol][nh] = true; //방문함.
					tomatoes[nrow][ncol][nh] = 1; //익음
					int nday = fday + 1;
					q.push(make_tuple(nrow, ncol, nh, nday));
					answer = max(answer, nday);//날짜 갱신
				}
 			}

		}
	}//end while

}


int main() {

	//입력
	cin >> M >> N >> H;

	vector<tuple<int, int, int, int>> tomato_pos;
	for (int i = 0; i < H; i++) { //높이
		for (int j = 0; j < N; j++) { //행
			for (int k = 0; k < M; k++) { //열
				cin >> tomatoes[j][k][i];
				if(tomatoes[j][k][i]==1)  q.push(make_tuple(j, k, i, 0)); //익은 토마토 우선 넣기
			}
		}
	}
	
	//탐색
	bfs();
	
	//출력
	//하나라도 0이면 -1 출력, 그게 아니라면 day 출력 
	for (int i = 0; i < H; i++) { //높이
		for (int j = 0; j < N; j++) { //행
			for (int k = 0; k < M; k++) { //열
				if (tomatoes[j][k][i] == 0) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	
	cout << answer << endl;

	return 0;
}