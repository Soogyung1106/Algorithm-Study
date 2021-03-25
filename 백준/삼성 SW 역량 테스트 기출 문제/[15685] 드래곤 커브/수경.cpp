#include <iostream>
#include <vector>
using namespace std;

bool visited[101][101]; //N개의 드래곤 커브가 지나간 좌표의 자리 저장
int N, y, x, d, g;
int moveY[4] = { 0, -1, 0, 1 };
int moveX[4] = { 1, 0, -1, 0 };

void makeCurv(int startY, int startX, int d, int g) {

	//0세대 
	int nextY = startY + moveY[d], nextX = startX + moveX[d];
	visited[startY][startX] = true;
	visited[nextY][nextX] = true; //이동

	//1세대~g세대 커브 생성
	vector<int> direction = { d }; //0~g세대까지 움직이는 방향 총 2^g개 저장 

	for (int i = 1; i <= g; i++){ 
		for (int j = direction.size()-1; j >= 0; j--) {
			int nextDir = (direction[j] + 1) % 4; //방향 생성
			direction.push_back(nextDir); 
	
			//방향에 따라 움직이며 지나간 좌표 체크
			nextY += moveY[nextDir], nextX += moveX[nextDir];
			visited[nextY][nextX] = true;
		}
	}

}

int countRect() {
	int rectangle = 0; //정사각형의 개수
	for (int i = 0; i < 100; i++) 
		for (int j = 0; j < 100; j++) 
			if (visited[i][j] && visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1])
				rectangle++;

	return rectangle;
}

int main() {

	//입력
	//freopen("input4.txt", "r", stdin);
	cin >> N;
	while (N--) {
		cin >> x >> y >> d >> g;
		makeCurv(y, x, d, g); //드래곤 커브 생성
	}
	
	//출력
	cout<< countRect() <<'\n';
	return 0;
}
