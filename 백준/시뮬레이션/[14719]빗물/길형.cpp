#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

//int N, M;

//void init()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//}
//
//int main(void)
//{
//	init();
//	cin >> N >> M;
//
//	vector<vector<int>> map(N + 1, vector<int>(M,0));
//
//	for (int x = 0; x < M; x++)
//	{
//		int temp;
//
//		cin >> temp;
//
//		map[N][x] = 1; // 땅 설정
//
//		for (int idx = 0; idx < temp; idx++)
//		{
//			int y = N - (idx + 1);
//			map[y][x] = 1;
//		}
//
//	}
//
//	for (int i = 0; i < map.size(); i++)
//	{
//		for (int j = 0 ; j < map[0].size(); j++)
//		{
//			cout << map[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

int main() 
{
	int N, M, K;
	int X, Y;
	int answer = 0;

	cin >> N >> M;
	vector<int> v(M);

	for (int i = 0; i < M; i++)
		cin >> v[i];

	for (int i = 1; i < M - 1; i++) 
	{
		int left = 0; 
		int right = 0;

		//왼쪽 최대 값
		for (int j = 0; j < i; j++)
		{
			left = max(left, v[j]);
		}

		//오른쪽 최대 값
		for (int j = M - 1; j > i; j--)
		{
			right = max(right, v[j]);
		}

		//빗물 계산
		answer += max(0, min(left, right) - v[i]);
	}

	cout << answer << endl;

	return 0;
}
