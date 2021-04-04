//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) { //(수, 빈도수)
		return a.second == b.second ? a.first > b.first : a.second > b.second;
	}
};
int A[101][101], curRow =3 , curCol = 3; //현재의 배열 상태, 행의 길이, 열의 길이
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; //힙 구조에 (수, 등장횟수) 저장

void heapify(int cnt[]) {
	int sizeMax = 0;
	for (int k = 1; k <= 100; k++) {
		if (sizeMax >= 100) break;
		if (cnt[k] != 0) {
			sizeMax += 2;
			pq.push({ k, cnt[k] });
		}
	}
}

void doR() { 

	for (int i = 1; i <= curRow; i++) { //행(Row)에 대해서 연산 수행
		
		//수의 등장 횟수 cnt에 저장
		int cnt[101]; memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= curCol; j++) cnt[A[i][j]]++;
		
		//우선순위 큐 pq에 (수, 등장 횟수) 저장
		heapify(cnt); 

		//최대 열의 길이 갱신.
		curCol = max(curCol, (int)pq.size() * 2);

		//우선순위 큐 순서대로 A의 행 초기화 
		for (int j = 1; j <= 100; j++)	A[i][j] = 0;

		int idx = 1;
		while (!pq.empty()) {
			A[i][idx] = pq.top().first; 
			A[i][idx+1] = pq.top().second; 
			idx+=2;
			pq.pop();
		}
	}

}

void doC() { 

	for (int i = 1; i <= curCol; i++) { //열(Col)에 대해서 연산 수행
		//수의 등장 횟수 cnt에 저장
		int cnt[101]; memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= curRow; j++) cnt[A[j][i]]++;

		//우선순위 큐 pq에 (수, 등장 횟수) 저장
		heapify(cnt);

		//최대 행의 길이 갱신
		curRow = max(curRow, (int)pq.size() * 2);

		//우선순위 큐 순서대로 A의 열 초기화
		for (int j = 1; j <= 100; j++) A[j][i] = 0;

		int idx = 1;
		while (!pq.empty()) {
			A[idx][i] = pq.top().first;
			A[idx+1][i] = pq.top().second;
			idx += 2;
			pq.pop();
		}
	}

}

int main() {

	//입력
	//freopen("input4.txt", "r", stdin); 
	int r, c, k;
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) 
		for (int j = 1; j <= 3; j++) 
			cin >> A[i][j];


	int time = 0;
	while (1) {
		//시간이 100초가 지났는데도 k가 아닌 경우
		if (time > 100) {
			cout << -1 << '\n';
			break;
		}

		//A[r][c] = k인지 검사
		if (A[r][c] == k) {
			cout << time << '\n';
			break;
		}

		//연산
		if (curRow >= curCol) doR();
		else doC();
		
		//시간 증감.
		time++;
	}

	return 0;
}