#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
int cntHome; //집의 개수 카운팅.
int moved[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; //방향 이동

void dfs(int i, int j) {
	//(i, j)부터 시작해서 탐색 시작. 
	visited[i][j] = true;
	cntHome++; //단지 내 집의 개수 증감.
	
	for (int k = 0; k < 4; k++) {
		int nextRow = i + moved[k][0];
		int nextCol = j + moved[k][1];

		if (0 <= nextRow && nextRow < map.size() && 0 <= nextCol && nextCol < map.size()) {
			if (map[nextRow][nextCol] &&!visited[nextRow][nextCol])
				dfs(nextRow, nextCol);
		}
	}

}

int main() {

	//입력 
	int n;
	cin >> n;
	map.resize(n, vector<int>(n));
	visited.resize(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			scanf_s("%1d", &map[i][j]);

	//탐색
	int answer=0; //단지의 개수 카운팅.
	vector<int> homes; //단지 내 집들의 개수 저장.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] && !visited[i][j]) {
				answer++;
				dfs(i, j); //(i,j) 부터 탐색 시작
				homes.push_back(cntHome);
				cntHome = 0; //초기화
			}
		}
	}
	
	//출력 
	cout << answer << endl;
	sort(homes.begin(), homes.end()); //오름차순 정렬
	for (auto home : homes)
		cout << home << endl;

	return 0;
}
