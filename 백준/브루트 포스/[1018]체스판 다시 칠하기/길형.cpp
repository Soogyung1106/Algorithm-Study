#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define MAX 8

using namespace std;

string white[MAX] = { "WBWBWBWB",
				   "BWBWBWBW",
				   "WBWBWBWB",
				   "BWBWBWBW",
				   "WBWBWBWB",
				   "BWBWBWBW",
				   "WBWBWBWB",
				   "BWBWBWBW" };

string black[MAX] = { "BWBWBWBW",
				   "WBWBWBWB",
				   "BWBWBWBW",
				   "WBWBWBWB",
				   "BWBWBWBW",
				   "WBWBWBWB",
				   "BWBWBWBW",
				   "WBWBWBWB" };

int check_white(vector<string> board, int x, int y)
{
	int count = 0;

	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if (white[i - x][j - y] != board[i][j])
				count++;
		}
	}
	return count;
}

int check_black(vector<string> board, int x, int y)
{
	int count = 0;

	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if (black[i - x][j - y] != board[i][j])
				count++;
		}
	}
	return count;
}
int main(void)
{
	int N, M;
	int answer = 64; // 8*8 다바꿔도 64임
	vector<string> board;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			answer = min(answer, min(check_white(board, i, j), check_black(board, i, j)));
		}
	}

	cout << answer;
	return 0;
}
