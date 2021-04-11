//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N, L, map[101][101], answer;

bool isStreet(vector<tuple<int, int>> v) {
	if (v.size() == 1) return true;
	
	vector<bool> install(v.size(), false); //설치 여부 체크
	for (int i = 0; i < v.size()-1; i++) {

		if (abs(get<0>(v[i]) - get<0>(v[i + 1])) != 1) return false; //(1) 높이 차

		int lowIdx = 0;//더 낮은 높이의 인덱스 구하기 
		if (get<0>(v[i]) > get<0>(v[i + 1])) lowIdx = i + 1;
		else lowIdx = i;

		if (get<1>(v[lowIdx]) < L) return false; //(2) 낮은 칸의 개수 >= L
		 
		if (install[lowIdx] && get<1>(v[lowIdx]) - L < L) return false; //(3) 이미 설치되어 있어서 설치 못할 경우

		install[lowIdx] = true; //경사로 설치.
	}

	return true;
}

int main() {

	//입력
	//freopen("input4.txt", "r", stdin);
	cin >> N >> L;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];

	//길 탐색
	for (int i = 0; i < N; i++) { //가로 방향(행) 
		//{높이, 개수} 저장
		vector<tuple<int, int>> v;
		int cnt = 1, height = map[i][0];
		for (int j = 1; j < N; j++) {
			if (map[i][j] == height) cnt++;
			else {
				v.push_back({ height, cnt }); //{높이, 개수} 저장
				height = map[i][j];
				cnt = 1;
			}
		}
		v.push_back({ height, cnt });

		//길 가능 여부 판단
		if (isStreet(v)) answer++; 
	}

	for (int i = 0; i < N; i++) { //세로 방향(열)
		
		//{높이, 개수} 저장
		vector<tuple<int, int>> v;
		int cnt = 1, height = map[0][i];
		for (int j = 1; j < N; j++) {
			if (map[j][i] == height) cnt++;
			else {
				v.push_back({ height, cnt }); 
				height = map[j][i];
				cnt = 1;
			}
		}
		v.push_back({ height, cnt });

		//길 가능 여부 판단
		if (isStreet(v)) answer++; 
	}
	

	//정답 출력
	cout << answer << '\n';

	return 0;
}
