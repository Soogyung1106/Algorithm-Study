//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
int N, area[21][21], visited[21][21];
int moveY[4] = { 0, 0, 1, -1 };
int moveX[4] = { 1, -1, 0, 0 };

void fillLine(int x, int y, int d1, int d2) { //1, 2, 3, 4, 5 구역을 나누는 경계선을 해당 숫자로 채움.

	//1 경계선
	for (int i = x - 1; i >= 1; i--)  visited[i][y] = 1;
	
	//2 경계선
	for (int i = y + d2 + 1; i <= N; i++)  visited[x + d2][i] = 2;

	//3 경계선
	for (int i = y - d1 - 1; i >= 1; i--)  visited[x + d1][i] = 3;

	//4 경계선
	for (int i = x + d1 + d2 + 1; i <= N; i++)  visited[i][y - d1 + d2] = 4;

	//5 경계선
	for (int i = x, j = y; i <= x + d1 && j >= y - d1; i++, j--)  visited[i][j] = 5;
	for (int i = x, j = y; i <= x + d2 && j <= y + d2; i++, j++)  visited[i][j] = 5;
	for (int i = x + d1, j = y - d1; i <= x + d1 + d2 && j <= y - d1 + d2; i++, j++)  visited[i][j] = 5;
	for (int i = x + d2, j = y + d2; i <= x + d2 + d1 && j >= y + d2 - d1; i++, j--)  visited[i][j] = 5;
}

void fillArea(int num, int y, int x) { //DFS로 탐색하며 채우기

	visited[y][x] = num;

	for (int i = 0; i < 4; i++) {
		int nextY = y + moveY[i], nextX = x + moveX[i];
		if (nextY < 1 || nextY > N || nextX < 1 || nextX > N) continue; //범위 밖
		if (visited[nextY][nextX]) continue; //이미 채워져 있다면

		fillArea(num, nextY, nextX);
	}
}

int getDiff() { //인구 차이의 최솟값을 구하는 함수

	int cnt[5] = { 0, 0, 0, 0, 0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j] == 1) cnt[0] += area[i][j];
			else if (visited[i][j] == 2) cnt[1] += area[i][j];
			else if (visited[i][j] == 3) cnt[2] += area[i][j];
			else if (visited[i][j] == 4) cnt[3] += area[i][j];
			else cnt[4] += area[i][j];
		}
	}

	return *max_element(cnt, cnt + 5) - *min_element(cnt, cnt + 5);
}


int main() {
	
	//입력
	//freopen("input3.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> area[i][j];
		}
	}

	//모든 경우의 수
	int answer = INF;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {

					//조건
					if (!(x < x + d1 + d2 && x + d1 + d2 <= N)) continue;
					if (!(1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= N)) continue;
					
					//초기화
					memset(visited, 0, sizeof(visited)); 
							
					//경계선 라인 1, 2, 3, 4, 5 visited에 채우기 
					fillLine(x, y, d1, d2);

					//구역 채우기
					fillArea(1, 1, 1); //1번, 시작위치(행, 열)
					fillArea(2, 1, N); 
					fillArea(3, N, 1);
					fillArea(4, N, N);

					//인구 차이의 최솟값 갱신
					answer = min(answer, getDiff());
				}
			}
		}
	}

	cout << answer << '\n';

	return 0;
}
