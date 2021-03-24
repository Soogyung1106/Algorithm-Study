#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, M, H, a, b, answer = INF, visited[34][34];

bool check() {
	//col 세로선의 결과 col가 나오는지 체크 

	for (int col = 1; col <= N; col++) { //세로선 기둥.
		int start = col; //출발선
		for (int row = 1; row <= H; row++) { //가로선
			//해당 row에 길이 있다면 
 			if (visited[row][start]) start++; //다음 세로선으로 이동 
			else if (visited[row][start - 1]) start--; //이전 세로선으로 이동
		}
		if (start != col) return false;
	}
	return true;
}

void search(int here, int cnt) {
	//기저조건
	if (cnt > 3) return;
	if (check()) { //i 세로선의 결과 i가 나오는지 체크 
		answer = min(answer, cnt);
		return;
	}

	for (int row = here; row <= H; row++) { //가로선 
		for (int col = 1; col <= N; col++) { //세로선

			//가로선을 추가할 수 없는 경우
			if (visited[row][col] || visited[row][col - 1] || visited[row][col + 1]) continue;
			
			//가로선 새로 추가.
			visited[row][col] = 1; //col 세로선 라인의 row 가로선을 추가. 
			search(row, cnt + 1);
			visited[row][col] = 0;
		}
	}
}

int main() {

	//입력
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> a >> b; 
		visited[a][b] = 1;
	}

	//탐색
	search(1, 0); //(1번 가로선부터 추가, 새로 추가한 가로선의 개수)
	
	//출력
	cout << ((answer == INF) ? -1 : answer) << "\n";
	return 0;
}
