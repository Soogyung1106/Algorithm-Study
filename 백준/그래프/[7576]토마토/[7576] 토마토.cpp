#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N; //가로, 세로 
vector<vector<int>> tomatoes;
vector<vector<bool>> visited;
int day = 0; //소요 시간
int moved[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue<pair<pair<int, int>, int>> q; //익은 토마토의 위치(x, y), 익는데 소요된 날

void bfs() {
	//익은 토마토의 위치를 기준으로 전체 탐색 
	while (!q.empty()) {
		pair<pair<int, int>, int> front = q.front();
		q.pop();

		for (auto mv : moved) {
			pair<int, int> next = { front.first.first + mv[0], front.first.second + mv[1]};
			
			//범위 내
			if (0 <= next.first && next.first < N && 0 <= next.second && next.second < M) {
				if (tomatoes[next.first][next.second] == 0 && !visited[next.first][next.second]) {
					tomatoes[next.first][next.second] = 1; //익힘
					visited[next.first][next.second] = true; //방문체크
					q.push({ next, front.second+1}); 
					day = max(day, front.second + 1); //날짜 카운팅
				}
			}
		}
	}

}

int main() {

	//방문 체크, 토마토 위치, 익은 토마토의 위치를 담은 배열  


	//입력 
	cin >> M >> N;	
	tomatoes.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomatoes[i][j];
			if (tomatoes[i][j] == 1) {
				q.push({ { i, j }, 0 }); //익은 토마토의 위치, 익는데 소요되는 날
				visited[i][j] = true;
			}
		}
	}
		
	//익히기, 날짜 카운팅
	bfs();

	//tomatos에 0(안 익은 것)이 있다면 -> return -1
	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomatoes[i][j] == 0) {
				flag = false;
				break;
			}
		}
	}

	//출력 
	if (!flag) cout << -1<<endl;
	else cout << day<<endl;

	return 0;
}