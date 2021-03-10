/* 시뮬레이션
뱀이 이동하려고 하는 다음 위치가..
(1) 빈 칸이라면. 
(2) 뱀의 몸통이라면. 
(3) 사과라면.

-> 뱀이 차지하고 있는 자리의 좌표를 deque pair(x, y)에 저장(꼬리와 머리 추가 삭제 편리)
-> 뱀이 차지하고 있는 자리: 2, 빈칸: 0, 사과: 1
-> 종료조건: 뱀이 이동하려는 다음 위치가 뱀의 몸통(2)이거나 벽(배열 범위 밖)을 만날 경우 
-> 방향을 바꾸는 조건: 일정한 time이 될 때마다 방향 바꿈.-> 수행 후 앞에서부터 차례로 삭제하기 위해 queue로 구현.  
*/

//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <deque>
#include <tuple>
using namespace std;

int N, K, L; 
int board[101][101]; //0으로 초기화(아무것도 없음.)
queue<tuple<int, char>> directions; //뱀의 이동 방향
deque<tuple<int, int>> snake; //뱀이 보드에서 차지하고 있는 몸통의 좌표(좌 끝: 꼬리, 우 끝: 머리)
int nextDir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} }; //이동 방향(→ ↓ ← ↑ )
int time = 0; 

void gameStart() {
	
	//뱀의 출발 위치
	int curY = 1, curX = 1;
	board[1][1] = 2; //보드에 표시
	snake.push_front({ 1, 1 }); //뱀의 몸통 생성
	
	int idx = 0; //nextDir 처음 이동 방향(→)

	while (1) {
		time++; //움직일 때마다 시간 증감.

		//다음 위치
		int nextY = curY + nextDir[idx][0];
		int nextX = curX + nextDir[idx][1];

		//종료조건: 뱀의 뱀의 몸통(2)이거나 벽(배열 범위 밖)을 만날 경우 
		if (board[nextY][nextX] == 2 || nextY <1 || nextY > N || nextX < 1 || nextX > N)
			break;

		//a. 빈칸이라면...
		if (board[nextY][nextX] == 0) {
			int tailY, tailX;
			tie(tailY, tailX) = snake.back();

			//보드에 표시
			board[nextY][nextX] = 2;  
			board[tailY][tailX] = 0; //꼬리부분은 보드에서 표시 없애기

			//뱀 몸통 갱신		 
			snake.push_front({ nextY, nextX }); //머리는 next로 이동
			snake.pop_back(); //꼬리는 빼기
		}
		
		//b. 사과라면...
		else if (board[nextY][nextX] == 1) {
			//보드에 표시 
			board[nextY][nextX] = 2; 

			//뱀 머리 갱신
			snake.push_front({ nextY, nextX });
		}

		
		if (!directions.empty()) { 
			//방향을 바꿀 시간이 되었다면..
			int timeToChangeDir; char dir;
			tie(timeToChangeDir, dir) = directions.front();

			if (time == timeToChangeDir) {
				if (dir == 'L')  idx = (idx + 1) % 4; //현재 방향에서 왼쪽으로 방향 바꿈.
				else  idx = (idx + 3) % 4; //오른쪽으로..
				directions.pop();
			}
		}

		//현재 좌표 갱신
		curY = nextY;
		curX = nextX;

	}//end while

}

int main() {
	
	
	//freopen("input1.txt", "r", stdin);
	//freopen("input2.txt", "r", stdin);
	//freopen("input3.txt", "r", stdin);


	//입력
	cin >> N; //보드의 크기
	cin >> K; //사과의 개수
	while (K--) {
		int y, x;
		cin >> y >> x;
		board[y][x] = 1; //사과 위치시킴.
	}

	cin >> L; //뱀의 방향 횟수
	while (L--) {
		int time; char dir;  //시간과 방향
		cin >> time >> dir;
		directions.push({ time, dir });
	}

	//뱀이 이동 시작.
	gameStart(); 

	//게임이 끝날 떄 몇 초였는지 출력
	cout << time << '\n'; 
	return 0;
}
