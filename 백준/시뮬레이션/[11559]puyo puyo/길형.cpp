#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#define endl "\n"

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N = 12;
string arr[12];
int visit[12][6];
bool break_check = false; // 4개 이상 모였는지 확인하는 변수

queue <pair<int, int>> q;
vector <pair<int, int>> v;

int DownPuyo(int y, int x) 
{
	int tempY = -1;

	for (int i = y; i < N; i++)
	{
		if (arr[i][x] == '.')
		{
			tempY = i;
		}
	}
	return tempY;
}

void bfs(int y, int x) 
{

	q.push({ y, x }); 
	v.push_back({ y,x }); 

	while (!q.empty()) 
	{

		int now_y = q.front().first;
		int now_x = q.front().second;
		visit[now_y][now_x] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int ny = now_y + dy[i];
			int nx = now_x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= 6 || visit[ny][nx]) continue;

			if (arr[now_y][now_x] == arr[ny][nx])
			{
				q.push({ ny, nx }); // 갈 수 있는 칸을 푸쉬
				v.push_back({ ny,nx }); // 방문할 경로를 푸쉬
				visit[ny][nx] = 1;
			}
		}
	}
}

int main() 
{
	int crash = 0, tempY = -1;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	while (true) 
	{

		
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < 6; j++) 
			{
				if (arr[i][j] != '.' && visit[i][j] != 1) //동시에 터질 수 있는 곳들이 visit에 1
				{
					bfs(i, j);
				}

				if (v.size() >= 4) // 4개 이상 연결됬을 경우 true로 설정
				{
					break_check = true;
				}

				if (v.size() < 4) // 4개 미만으로 연결된 경우 visit 취소
				{ 
					for (int i = 0; i < v.size(); i++) 
					{
						visit[v[i].first][v[i].second] = 0;
					}
				}
				 
				v.clear();
			}
		}

		
		if (break_check == true) crash += 1; 
		else if (break_check == false) break; 
    
		for (int i = 0; i < N; i++) // visit가 1로 표시된 곳을 모두 . 으로 만듦
		{
			for (int j = 0; j < 6; j++) 
			{
				if (visit[i][j] == 1) 
				{
					arr[i][j] = '.';
				}
			}
		}
		
		for (int i = N - 2; i >= 0; i--) // 블럭 내리기
		{
			for (int j = 0; j < 6; j++) 
			{
				tempY = -1;
				if (arr[i][j] != '.') 
				{
					tempY = DownPuyo(i, j);
				}
				if (tempY != -1) 
				{
					arr[tempY][j] = arr[i][j]; // 블록 이동
					arr[i][j] = '.'; // 이전 자리 . 으로 바꾸기
				}
			}
		}
		
		break_check = false;

		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < 6; j++) 
			{
				visit[i][j] = 0;
			}
		}
	}

	cout << crash;

	return 0;
}
