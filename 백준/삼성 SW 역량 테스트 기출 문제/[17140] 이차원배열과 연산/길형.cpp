#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 150

using namespace std;

int map[MAX][MAX];
int number[101];
int r, c, k;
int row_size = 3, column_size = 3;
vector<pair<int, int>> temp;

void column_sort() 
{
	int new_row = 0;

	for (int i = 0; i < column_size; i++) 
	{

		for (int j = 0; j < row_size; j++) 
		{
			number[map[j][i]]++;
		}

		for (int k = 1; k <= 100; k++) 
		{
			if (number[k] != 0) 
			{
				temp.push_back({ number[k], k });
				number[k] = 0;
			}
		}

		sort(temp.begin(), temp.end());


		int temp_size = temp.size();
		int new_size = temp_size * 2;

		new_row = max(new_row, new_size);

		int index = 0;

		for (int k = 0; k < new_size; k += 2) 
		{
			map[k][i] = temp[index].second;
			map[k + 1][i] = temp[index].first;
			index++;
		}

		for (int k = new_size; k < row_size; k++) 
		{
			map[k][i] = 0;
		}

		temp.clear();
	}
	row_size = new_row;
}

void row_sort() 
{
	int new_column = 0; // 새로운 열 크기 중 최댓값

	for (int i = 0; i < row_size; i++) 
	{
		for (int j = 0; j < column_size; j++) 
		{
			number[map[i][j]]++; //숫자의 등장 횟수 카운트, number[index] 값 증가.
		}
		
		for (int k = 1; k <= 100; k++)
		{
			if (number[k] != 0) //개수가 0개가 아니라면 temp에 넣어주고 number배열은 다시 0으로 초기화
			{
				temp.push_back({ number[k], k }); // 수의 등장횟수로 정렬, 벡터에 순서대로 push
				number[k] = 0;
			}
		}

		sort(temp.begin(), temp.end());

		int temp_size = temp.size();
		int new_size = temp_size * 2; // temp의 자료형 pair

		new_column = max(new_column, new_size); // 열 사이즈 재조정

		int index = 0;

		for (int k = 0; k < new_size; k += 2) 
		{
			
			map[i][k] = temp[index].second; // 수를 뒤에 넣었으므로 second를 먼저
			map[i][k + 1] = temp[index].first; // 수의 등장 횟수를 first에 넣어놨으므로 나중에
			index++;
		}

		
		for (int k = new_size; k < column_size; k++) 
		{
			map[i][k] = 0; // 남은 칸 0
		}

		temp.clear();
	}
	column_size = new_column; //열 크기는 이번 연산에서 가장 긴 열의 크기로
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			cin >> map[i][j];
		}
	}

	r--; // index 맞추기
	c--; // index 맞추기

	int time = 0;

	while (true)
	{
		if (map[r][c] == k) // 찾은 경우
		{
			cout << time << endl;
			break;
		}

		time++;

		if (time > 100) // 시간초과
		{
			cout << -1 << endl;
			break;
		}

		if (row_size >= column_size)
		{
			row_sort();
		}
		else
		{
			column_sort();
		}
	}

	return 0;
}
