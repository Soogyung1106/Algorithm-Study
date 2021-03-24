#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define N_MAX 12
#define H_MAX 32
#define endl "\n"

using namespace std;

int N, M, H;
int map[H_MAX][N_MAX]; // 가로선 위치(행), 세로선 위치(열)

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

bool check() 
{
	for (int i = 1; i <= N; i++) 
	{
		int y = 0;
		int x = i;

		while (true) // 사다리 타기
		{
			
			if (y == H + 1) // 바닥 도착
			{
				if (x == i) break; // 시작[i] == 결과[i] 맞으면
				else return false;
			}

			if (map[y + 1][x] == 1) // 오른쪽(->) 이동
			{
				x++;
			}
			else if (map[y + 1][x] == 2) // 왼쪽(<-) 이동
			{
				x--;
			}
			
			y++; //한칸 내려간다.
		}
	}

	return true;
}

int select(int y, int index) 
{
	if (index > 3) return -1;

	int answer = -1;

	for (int i = y; i <= H; i++)
	{
		for (int j = 1; j < N; j++) 
		{
			if (map[i][j] != 0) continue; // 이미 연결되어 있으면
			if (map[i][j + 1] != 0) continue;

			map[i][j] = 1; // i, i+1 연결
			map[i][j + 1] = 2;

			if (check()) 
			{
				answer = index; // 시작[i] == 끝[i] index(사용한 가로선 수)를 answer에 저장
			}

			int temp = select(i, index + 1); // 다음 탐색 y+1 행으로 이동

			if (answer == -1) answer = temp; //answer가 초기값이라면 다음 탐색에서 받아온 temp를 저장

			
			map[i][j] = 0; // 방금 놓았던 가로선 제거
			map[i][j + 1] = 0; // 방금 놓았던 가로선 제거
		}
	}

	return answer;
}


int main() 
{
	init();
	cin >> N >> M >> H;

	int a, b;
	
	for (int i = 0; i < M; i++) 
	{
		cin >> a >> b;
		map[a][b] = 1; // 1 : 오른쪽(->)으로 이동
		map[a][b + 1] = 2; // 2 : 왼쪽(<-)으로 이동
	}

	if (check()) cout << 0 << endl;
	else cout << select(1, 1) << endl;

	return 0;
}
