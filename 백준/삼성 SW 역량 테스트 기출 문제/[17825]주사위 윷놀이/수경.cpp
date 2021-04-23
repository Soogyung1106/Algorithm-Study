#include<iostream>
using namespace std;

int arr[10]; // 주사위
int mal[4]; // 현재 말의 위치
int map[35]; // 윷놀이 판
int turn[35]; // - 판에서 방향 전환
bool check[35]; // - 현 위치에 말이 있는지 확인
int score[35]; // - 윷놀이 판의 점수
int ans = 0; // 최종 값

void dfs(int cnt, int sum) {
	if (cnt == 10) {
		//실행 할 곳
		if (sum > ans) ans = sum;

		return;
	}
	for (int i = 0; i < 4; i++) {
		
		int prev = mal[i]; // 현재 말 위치
		int now = prev; //이동 할 말 위치
		// 움직여야 하는 횟수
		int move = arr[cnt];

		// 만약 현재 위치가 방향 전환 해야하는 곳 이라면..
		if (turn[now] > 0) {
			now = turn[now];
			move -= 1;
		}
		// 주사위 만큼 이동
		while (move--) {
			now = map[now];
		}

		if (now != 21 && check[now] == true) continue;

		check[prev] = false;
		check[now] = true;
		mal[i] = now;

		dfs(cnt + 1, sum + score[now]);

		mal[i] = prev;
		check[prev] = true;
		check[now] = false;
	}
}

int main() {

	//맵 초기화(그 다음 가야할 곳)
	for (int i = 0; i < 21; i++) map[i] = i + 1;
	map[21] = 21;
	for (int i = 22; i < 27; i++) map[i] = i + 1;
	
	//방향 전환 초기화(그 다음 가야할 곳)
	turn[5] = 22; turn[10] = 31; turn[15] = 28;
	turn[25] = 26;
	
	//점수 초기화
	for (int i = 0; i < 21; i++) score[i] = i * 2;
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[31] = 22; score[32] = 24; score[28] = 28;
	score[29] = 27; score[30] = 26; score[25] = 25;
	score[26] = 30; score[27] = 35;

	// 주사위 입력 받기.
	for (int i = 0; i < 10; i++) cin >> arr[i];

	//탐색
	dfs(0, 0);

	//출력
	cout << ans << "\n";
	return 0;
}
