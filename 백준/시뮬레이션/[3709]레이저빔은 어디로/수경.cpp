#include<bits/stdc++.h>
using namespace std;

int board[52][52];

void go(int x, int y, int dir)
{
	int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
	x += dx[dir]; y += dy[dir];

	while (board[x][y] != -1) { //레이저가 보드를 벗어난 경우가 아니라면..
		if (board[x][y] == 1) //우향우 거울
			dir = (dir + 1) % 4;
		x += dx[dir], y += dy[dir];
	}

	cout << x << " " << y << "\n";
}

void input()
{
	int n, r, x, y;
	cin >> n >> r;
	for (int i = 0; i <= n + 1; i++) { //보드 밖 -1 초기화
		board[0][i] = -1;
		board[i][0] = -1;
		board[n + 1][i] = -1;
		board[i][n + 1] = -1;
	}

	for (int i = 0; i < r; i++) { //우향우 거울
		cin >> x >> y;
		board[x][y] = 1;
	}

	cin >> x >> y; //레이저빔 출발 위치
	if (x == 0) go(x, y, 2);//하
	else if (x == n + 1) go(x, y, 0);//상
	else if (y == 0) go(x, y, 1);//우
	else go(x, y, 3);//좌
}


int main()
{
	int t;
	cin >> t;
	while (t--) {
		input();
		memset(board, 0, sizeof(board));
	}
}
