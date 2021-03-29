#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <deque>
#define endl "\n"
#define MAX 10

using namespace std;

int map[MAX][MAX];
int energy[MAX][MAX];
deque<int> tree[MAX][MAX];
deque<int> dead_tree[MAX][MAX];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,1,-1,-1,0,1 }; 
int N, M, K;



void spring()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) 
		{
			int size = tree[i][j].size(); 
			sort(tree[i][j].begin(), tree[i][j].end());
			
			for (int k = 0; k < size; k++)
			{ 
				int age = tree[i][j].front();
				tree[i][j].pop_front();

				if (map[i][j] >= age) // 남아있는 영양분이 나무의 나이보다 많다면
				{
					map[i][j] -= age;
					age++;
					tree[i][j].push_back(age);
				} 
				else
				{
					dead_tree[i][j].push_back(age);
				}
			}
		} 
	} 
} 

void summer() 
{ 
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		{ 
			while (!dead_tree[i][j].empty()) // 죽은 나무가 있다면, 죽은 나무의 나이 1/2이 영양분이 된다.
			{ 
				int age = dead_tree[i][j].front();
				dead_tree[i][j].pop_front();
				map[i][j] += age / 2; 
			} 
		} 
	} 
}

void autumn() 
{
	deque<int> next_tree[MAX][MAX];
	
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) 
		{ 
			int size = tree[i][j].size();

			for (int k = 0; k < size; k++) 
			{ 
				int age = tree[i][j].front();
				tree[i][j].pop_front();

				if (age % 5 == 0) // 나이가 5의 배수이면 1살짜리 나무가 8방향에 생김
				{ 
					for (int d = 0; d < 8; d++) 
					{
						int nx = i + dx[d], ny = j + dy[d];

						if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue; 
						next_tree[nx][ny].push_back(1); 
					} 
				}

				tree[i][j].push_back(age);
			} 
		} 
	} 
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{ 
			while (!next_tree[i][j].empty()) // 번식하는 나무가 있으면, 나무를 심는다.
			{ 
				int age = next_tree[i][j].front();
				next_tree[i][j].pop_front();
				tree[i][j].push_front(age);
			}
		}
	} 
} 

void winter() 
{ 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)  // 겨울의 영양소 보충
		{ 
			map[i][j] += energy[i][j];
		} 
	}
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main() 
{ 
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) 
		{ 
			cin >> energy[i][j];
			map[i][j] = 5;
		} 
	} 

	for (int i = 0; i < M; i++)
	{
		int x, y, age;

		cin >> x >> y >> age; 
		x--;
		y--;

		tree[x][y].push_back(age);
	} 

	for (int i = 0; i < K; i++)
	{
		spring();
		summer();
		autumn();
		winter();
	}

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer += tree[i][j].size();
		}
	}

	cout << answer << endl;

	return 0;
}
