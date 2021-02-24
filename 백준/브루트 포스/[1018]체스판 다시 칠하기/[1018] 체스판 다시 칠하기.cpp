#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char board[50][50];
int N, M;
char case1[9][9] = { "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW" };
char case2[9][9] = { "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};

int main() {

	//입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	
	int MIN = 1000000;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) { // 시작점 (i, j)

			int diffToCase1 = 0, diffToCase2 = 0;
			for (int row = i; row < i + 8; row++) {
				for (int col = j; col < j + 8; col++) { //8x8 다른개수 체크
					if (board[row][col] != case1[row - i][col - j]) diffToCase1++;
					if (board[row][col] != case2[row - i][col - j]) diffToCase2++;
				}
			}
			
			MIN = min(MIN, min(diffToCase1, diffToCase2));
		}
	}

	cout << MIN;
		
	return 0;
}
