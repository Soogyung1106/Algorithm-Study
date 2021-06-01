//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int N, M, R, score, dir;
int board[101][101], upDown[101][101];
int mX[] = { 0, 0, 1, -1 }, mY[] = { 1, -1, 0, 0 };

void setDir(char D){
	if (D == 'E') dir = 0; //동
	else if (D == 'W') dir = 1; //서
	else if (D == 'S') dir = 2; //남
	else if (D == 'N') dir = 3; //북
}

void pushDomino(int X, int Y) {
	queue<pair<int, int>> q;

	int len = board[X][Y]; //미뤄질 길이
	for (int i = 1; i <= len; i++) {
		if (upDown[X][Y]) { //서 있다면 밀기.
			upDown[X][Y] = 0;
			score++; //넘어뜨리면서 점수 카운팅.
			if(i > 1) q.push({ X, Y });
		}
		
		X += mX[dir], Y += mY[dir]; //방향대로 한 칸 이동.		
		if (X < 1 || X > N || Y < 1 || Y > M) return; //범위 넘어간다면 종료 
	}

	//연쇄 밀기 
	while (!q.empty()) {
		pair<int, int> p = q.front();
		pushDomino(p.first, p.second); //재귀적으로 호출
		q.pop();
	}
}


int main() {

	//입력
	//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input1.txt", "r", stdin);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j]; //도미노의 길이 입력


	memset(upDown, 1, sizeof(upDown)); //시작할 때는 도미노가 모두 서 있는 상태
	for (int i = 0; i < R; i++) {
		int X, Y; char D;
		cin >> X >> Y >> D;
		setDir(D); //방향 세팅
		if(upDown[X][Y]) pushDomino(X, Y); //공격(밀기) -> 도미노가 서 있을 경우에만 해당.
		
		cin >> X >> Y;
		upDown[X][Y] = 1; //수비(세우기)
	}

	//출력
	cout << score << '\n';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++){
			char c = ' ';
			upDown[i][j] ? c = 'S' : c = 'F';
			cout << c << " ";
		}
		cout << '\n';
	}

	return 0;
}
