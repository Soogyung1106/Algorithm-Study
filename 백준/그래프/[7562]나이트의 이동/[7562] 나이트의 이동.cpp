#include <queue>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int I; //한 변 길이
vector<vector<int>> visited;
int mvY[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int mvX[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int bfs(tuple<int, int> from, tuple<int, int> to) {
	//시작 위치와 도착 위치를 주고 도착위치가 되면 최단 거리 반환
	
	if (from == to) return 0; //예외

	queue<tuple<int, int>> q;
	q.push(from);

	while (!q.empty()) {
		int frontY, frontX;
		tie( frontY, frontX ) = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextY = frontY + mvY[i];
			int nextX = frontX + mvX[i];

			//범위내
			if (0 <= nextY && nextY < I && 0 <= nextX && nextX < I) {
				if (!visited[nextY][nextX]) {
					visited[nextY][nextX] = visited[frontY][frontX] + 1; //방문 표시, 거리 갱신
					q.push(make_tuple(nextY, nextX)); 

					if (nextY == get<0>(to) && nextX == get<1>(to)) //도착했다면.
						return visited[nextY][nextX];
				}
			}
		}
	}

}


int main() {

	//입력
	int T; //테.케 개수
	cin >> T; 

	vector<int> answer;
	for (int i = 0; i < T; i++) {
		cin >> I; //체스판 한 변 길이
		visited.resize(I, vector<int>(I, 0));

		int fromY, fromX;  //출발 위치
		cin >> fromY >> fromX;  

		int toY, toX; 
		cin >> toY >> toX; //도착 위치 

		//탐색
		answer.push_back( bfs(make_tuple(fromY, fromX), make_tuple(toY, toX)));

		//초기화
		visited.clear();
	}

	//출력
	for (auto v : answer)
		cout << v << endl;
	
	return 0;
}