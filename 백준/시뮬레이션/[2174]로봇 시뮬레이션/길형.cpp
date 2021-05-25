#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

int A, B, N, M;

int check[102][102];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct Robot {
	int x;
	int y;
	int dir;
};

vector<Robot> vt;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main() 
{
	init();
	cin >> A >> B;
	cin >> N >> M;

	int x, y, dir;
	char d;

	//index 1부터 시작하기위해 아무 값 넣어줌
	vt.push_back({ -1, -1, -1 });

	for (int i = 1; i <= N; i++) 
	{
		cin >> x >> y >> d;

		if (d == 'N') dir = 1;
		else if (d == 'E') dir = 2;
		else if (d == 'S') dir = 3;
		else dir = 0;

		vt.push_back({ x, y, dir });
		check[x][y] = i;
	}


	int num;
	char order;
	int orderCnt;

	int crashWall = 0; //벽에 부딪힌 로봇 번호를 저장
	int lastRobot = 0; //다른 로봇에 부딪힌 현재 이동 로봇을 저장
	int crashRobot = 0; //현재 이동중인 로봇이 부딪힌 다른 로봇의 번호를 저장


	while (M--) 
	{
		cin >> num >> order >> orderCnt;

		//잘못된 명령이 발생해서 벽이나 로봇이 부딪힌 경우 넘어가서 입력만 계속 받는다.
		if (crashWall || crashRobot) continue;

		x = vt[num].x;
		y = vt[num].y;
		dir = vt[num].dir;

		//명령 반복 횟수만큼 반복
		while (orderCnt--) 
		{
			if (order == 'L') 
			{
				//왼쪽 90도 회전
				dir = (dir + 3) % 4;
				vt[num].dir = dir;
			}
			else if (order == 'R') 
			{
				//오른쪽 90도 회전
				dir = (dir + 1) % 4;
				vt[num].dir = dir;
			}
			else if (order == 'F') 
			{

				//이전 위치 비워준다.
				check[x][y] = 0;

				x = x + dx[dir];
				y = y + dy[dir];

				if (x < 1 || y < 1 || x > A || y > B) 
				{
					//벽에 부딪힘
					crashWall = num;
					break;
				}
				else if (check[x][y] != 0)
				{
					//로봇에 부딪힘
					lastRobot = num;
					crashRobot = check[x][y];
					break;
				}
				else 
				{
					//이동
					vt[num].x = x;
					vt[num].y = y;
					check[x][y] = num;
				}
			}

		}
	}

	if (crashWall) cout << "Robot " << crashWall << " crashes into the wall" << endl;
	else if (crashRobot) cout << "Robot " << lastRobot << " crashes into robot " << crashRobot << endl;
	else cout << "OK" << endl;

	return 0;
}
