//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N, answer;
vector<vector<int>> map(21, vector<int>(21, 0));

vector<vector<int>> moveUp(vector<vector<int>> curMap) {
	
	for (int i = 0; i < N; i++) { //세로 열 
		vector<tuple<int, bool>> newElem;   //(숫자, 합쳐진 여부)
		for (int j = 0; j < N; j++) { //행
			if (curMap[j][i] == 0) continue;
			if (newElem.empty()) {
				newElem.push_back({ curMap[j][i] , false });
				continue;
			}

			//같은 값이고 합쳐진 적 없다면..
			tuple<int, int> back = newElem.back();
			if (get<0>(back) == curMap[j][i] && !get<1>(back))
				newElem[newElem.size() - 1] = { 2 * curMap[j][i], true };
			else
				newElem.push_back({ curMap[j][i] , false });
		}

		//newElem 넣은 것 앞에서부터 차례로 curMap에 넣기 
		if (newElem.empty()) continue;
		int k = 0;
		for (int j = 0; j < N; j++) {
			if (j < newElem.size()) curMap[k][i] = get<0>(newElem[j]);
			else curMap[k][i] = 0;
			k++;
		}
	}

	return curMap;
}

vector<vector<int>> moveDown(vector<vector<int>> curMap) {

	for (int i = 0; i < N; i++) { //세로 열 
		vector<tuple<int, bool>> newElem;   //(숫자, 합쳐진 여부)
		for (int j = N-1; j > -1; j--) { //행
			if (curMap[j][i] == 0) continue;
			if (newElem.empty()) {
				newElem.push_back({ curMap[j][i] , false });
				continue;
			}

			//같은 값이고 합쳐진 적 없다면..
			tuple<int, int> back = newElem.back();
			if (get<0>(back) == curMap[j][i] && !get<1>(back))
				newElem[newElem.size() - 1] = { 2 * curMap[j][i], true };
			else
				newElem.push_back({ curMap[j][i] , false });
		}

		//newElem 넣은 것 앞에서부터 차례로 curMap에 넣기 
		if (newElem.empty()) continue;
		int k = N-1;
		for (int j = 0; j < N; j++) {
			if (j < newElem.size()) curMap[k][i] = get<0>(newElem[j]);
			else curMap[k][i] = 0;
			k--;
		}
	}

	return curMap;
}

vector<vector<int>> moveLeft(vector<vector<int>> curMap) {

	for (int i = 0; i < N; i++) { //가로 행 
		vector<tuple<int, bool>> newElem;   //(숫자, 합쳐진 여부)
		for (int j = 0; j < N; j++) { //열
			if (curMap[i][j] == 0) continue;
			if (newElem.empty()) {
				newElem.push_back({ curMap[i][j] , false });
				continue;
			}

			//같은 값이고 합쳐진 적 없다면..
			tuple<int, int> back = newElem.back();
			if (get<0>(back) == curMap[i][j] && !get<1>(back))
				newElem[newElem.size() - 1] = { 2 * curMap[i][j], true };
			else
				newElem.push_back({ curMap[i][j] , false });
		}

		//newElem 넣은 것 앞에서부터 차례로 curMap에 넣기 
		if (newElem.empty()) continue;
		int k = 0;
		for (int j = 0; j < N; j++) {
			if (j < newElem.size()) curMap[i][k] = get<0>(newElem[j]);
			else curMap[i][k] = 0;
			k++;
		}
	}

	return curMap;
}

vector<vector<int>> moveRight(vector<vector<int>> curMap) {

	for (int i = 0; i < N; i++) { //가로 행 
		vector<tuple<int, bool>> newElem;   //(숫자, 합쳐진 여부)
		for (int j = N - 1; j > -1; j--) { //열
			if (curMap[i][j] == 0) continue;
			if (newElem.empty()) {
				newElem.push_back({ curMap[i][j] , false });
				continue;
			}

			//같은 값이고 합쳐진 적 없다면..
			tuple<int, int> back = newElem.back();
			if (get<0>(back) == curMap[i][j] && !get<1>(back))
				newElem[newElem.size() - 1] = { 2 * curMap[i][j], true };
			else
				newElem.push_back({ curMap[i][j] , false });
		}

		//newElem 넣은 것 앞에서부터 차례로 curMap에 넣기 
		if (newElem.empty()) continue;
		int k = N - 1;
		for (int j = 0; j < N; j++) {
			if (j < newElem.size()) curMap[i][k] = get<0>(newElem[j]);
			else curMap[i][k] = 0;
			k--;
		}
	}

	return curMap;
}

int biggestBlock(vector<vector<int>> curMap) {
	int MAX = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			MAX = max(MAX, curMap[i][j]);
	return MAX;
}

void moveBlock(vector<vector<int>> curMap, int depth) {
	//기저 조건
	if (depth > 5) { //5번 이동
		answer = max(answer, biggestBlock(curMap)); //curMap 중 가장 큰 수 탐색
		return; //탐색 종료 
	}

	//탐색
	moveBlock(moveUp(curMap), depth+1); //위
	moveBlock(moveDown(curMap), depth + 1); //아래
	moveBlock(moveLeft(curMap), depth + 1); //왼
	moveBlock(moveRight(curMap), depth + 1); //오

}

int main() {
	//freopen("input1.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];

	//브루트 포스, 재귀 (각 단계에서 이동할 수 있는 모든 경우의 수 탐색)
	moveBlock(map, 1);
	cout << answer << '\n';

	return 0;
}
