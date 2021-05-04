#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	bool answer = false;
	int M = key.size();
	int N = lock.size();

	for (int time = 0; time < 4; time++) // 시계 방향으로 90도씩 360도 회전
	{
		//newkey 초기화
		vector<vector<int>> newkey(M, vector<int>(M, 0));

		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				newkey[j][M - 1 - i] = key[i][j];

		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				key[i][j] = newkey[i][j];

		for (int i = 0; i < N + M - 1; i++) //자물쇠랑 열쇠랑 맞춰보는 것 , 총 경우의 수는 (N+M-1)^2의 경우의 수
		{
			for (int j = 0; j < N + M - 1; j++)
			{
				//큰 자물쇠 newlock 초기화
				vector<vector<int>> newlock(2 * M - 2 + N, vector<int>(2 * M - 2 + N, 0));

				for (int ii = 0; ii < N; ii++)
				{
					for (int jj = 0; jj < N; jj++)
					{
						newlock[ii + M - 1][jj + M - 1] = lock[ii][jj];
					}
				}


				//newlock이랑 newkey 합치기
				for (int ii = 0; ii < M; ii++)
				{
					for (int jj = 0; jj < M; jj++)
					{
						newlock[ii + i][jj + j] += newkey[ii][jj];
					}
				}

				int count = 0;

				for (int ii = M - 1; ii < M + N - 1; ii++)
				{
					for (int jj = M - 1; jj < M + N - 1; jj++)
					{
						if (newlock[ii][jj] == 1)
						{
							count++;
						}
					}
				}
				if (count == N * N)
				{

					return true;
				}

			}
		}

	}

	return false;
}
