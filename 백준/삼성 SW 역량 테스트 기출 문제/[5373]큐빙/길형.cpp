#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

const int MAX = 3;

int N;
string color = "wyrogb";
string flip;
char cube[6][3][3]; //U D F B L R
char copy2d[3][3];

// U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면
// +인 경우에는 시계 방향 (그 면을 바라봤을 때가 기준), -인 경우에는 반시계 방향
// 흰색은 w, 노란색은 y, 빨간색은 r, 오렌지색은 o, 초록색은 g, 파란색은 b

void ClockSide(int num)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			copy2d[i][j] = cube[num][i][j];

	//윗 열
	for (int i = 0; i < 3; i++)
		cube[num][0][i] = copy2d[2 - i][0];
	//가운데 열
	cube[num][1][0] = copy2d[2][1];
	cube[num][1][2] = copy2d[0][1];
	//아랫 열
	for (int i = 0; i < 3; i++)
		cube[num][2][i] = copy2d[2 - i][2];
}

void RiverseSide(int num)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			copy2d[i][j] = cube[num][i][j];
	//윗 열
	for (int i = 0; i < 3; i++)
		cube[num][0][i] = copy2d[i][2];
	//가운데 열
	cube[num][1][0] = copy2d[0][1];
	cube[num][1][2] = copy2d[2][1];
	//아랫 열
	for (int i = 0; i < 3; i++)
		cube[num][2][i] = copy2d[i][0];
}

//윗면을 기준으로 회전
void U(int num)
{
	char temp[3];
	for (int i = 0; i < 3; i++)
		temp[i] = cube[4][num][i];
	for (int i = 0; i < 3; i++)
		cube[4][num][i] = cube[2][num][i];
	for (int i = 0; i < 3; i++)
		cube[2][num][i] = cube[5][num][i];
	for (int i = 0; i < 3; i++)
		cube[5][num][i] = cube[3][num][i];
	for (int i = 0; i < 3; i++)
		cube[3][num][i] = temp[i];
}

//아랫면을 기준으로 회전
void D(int num)
{
	char temp[3];
	for (int i = 0; i < 3; i++)
		temp[i] = cube[4][num][i];
	for (int i = 0; i < 3; i++)
		cube[4][num][i] = cube[3][num][i];
	for (int i = 0; i < 3; i++)
		cube[3][num][i] = cube[5][num][i];
	for (int i = 0; i < 3; i++)
		cube[5][num][i] = cube[2][num][i];
	for (int i = 0; i < 3; i++)
		cube[2][num][i] = temp[i];
}

//앞면을 기준으로 회전
void F(int num)
{
	char temp[3];
	int idx = (num == 0 ? 2 : 0);

	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][num][i];
	for (int i = 0; i < 3; i++)
		cube[0][num][i] = cube[4][2 - i][num];
	for (int i = 0; i < 3; i++)
		cube[4][i][num] = cube[1][idx][i];
	for (int i = 0; i < 3; i++)
		cube[1][idx][i] = cube[5][2 - i][idx];
	for (int i = 0; i < 3; i++)
		cube[5][i][idx] = temp[i];
}

//뒷면을 기준으로 회전
void B(int num)
{
	char temp[3];
	int idx = (num == 0) ? 2 : 0;

	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][num][i];
	for (int i = 0; i < 3; i++)
		cube[0][num][i] = cube[5][i][idx];
	for (int i = 0; i < 3; i++)
		cube[5][i][idx] = cube[1][idx][2 - i];
	for (int i = 0; i < 3; i++)
		cube[1][idx][i] = cube[4][i][num];
	for (int i = 0; i < 3; i++)
		cube[4][i][num] = temp[2 - i];
}

//왼쪽면을 기준으로 회전
void L(int num)
{
	char temp[3];
	int idx = (num == 0 ? 2 : 0);

	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][i][num];
	for (int i = 0; i < 3; i++)
		cube[0][i][num] = cube[3][2 - i][idx];
	for (int i = 0; i < 3; i++)
		cube[3][i][idx] = cube[1][2 - i][num];
	for (int i = 0; i < 3; i++)
		cube[1][i][num] = cube[2][i][num];
	for (int i = 0; i < 3; i++)
		cube[2][i][num] = temp[i];
}

//오른쪽면을 기준으로 회전
void R(int num)
{
	char temp[3];
	int idx = (num == 0 ? 2 : 0);

	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][i][num];
	for (int i = 0; i < 3; i++)
		cube[0][i][num] = cube[2][i][num];
	for (int i = 0; i < 3; i++)
		cube[2][i][num] = cube[1][i][num];
	for (int i = 0; i < 3; i++)
		cube[1][i][num] = cube[3][2 - i][idx];
	for (int i = 0; i < 3; i++)
		cube[3][i][idx] = temp[2 - i];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					cube[i][j][k] = color[i];

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> flip;

			//1. 기준면을 돌리고
			//2. 나머지 면들의 변화를 적용한다
			switch (flip[0])
			{
			case 'U':
				if (flip[1] == '+')
				{
					ClockSide(0);
					U(0);
				}
				else
				{
					RiverseSide(0);
					D(0);
				}
				break;
			case 'D':
				if (flip[1] == '+')
				{
					ClockSide(1);
					D(2);
				}
				else
				{
					RiverseSide(1);
					U(2);
				}
				break;
			case 'F':
				if (flip[1] == '+')
				{
					ClockSide(2);
					F(2);
				}
				else
				{
					RiverseSide(2);
					B(2);
				}
				break;
			case 'B':
				if (flip[1] == '+')
				{
					ClockSide(3);
					B(0);
				}
				else
				{
					RiverseSide(3);
					F(0);
				}
				break;
			case 'L':
				if (flip[1] == '+')
				{
					ClockSide(4);
					L(0);
				}
				else
				{
					RiverseSide(4);
					R(0);
				}
				break;
			case 'R':
				if (flip[1] == '+')
				{
					ClockSide(5);
					R(2);
				}
				else
				{
					RiverseSide(5);
					L(2);
				}
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << cube[0][i][j];
			cout << endl;
		}
	}
	return 0;
}
