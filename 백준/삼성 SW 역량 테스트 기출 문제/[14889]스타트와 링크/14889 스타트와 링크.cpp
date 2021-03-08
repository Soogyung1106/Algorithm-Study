#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 20;

int main() {
	
	//입력
	int N;
	cin >> N;
	
	int S[MAX][MAX];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			cin >> S[i][j];
	
	//N개를 스타트팀과 링크 팀으로 나누는 경우의 수 
	vector<int> tmp(N, 0);
	for (int i = 0; i < N / 2; i++) tmp[i] = 1; //초기화
	sort(tmp.begin(), tmp.end());

	int answer = 9876543210; //두 팀의 능력치 차이
	do {
		//스타트팀과 링크팀에 팀원 분배
		vector<int> start; vector<int> link; 
		for (int i = 0; i < N; i++) {
			if (tmp[i] == 1) start.push_back(i);
			else link.push_back(i);
		}

		//각 팀의 능력치 계산 
		int powerS = 0, powerL = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				int x = start[i], y = start[j];
				powerS += (S[x][y] + S[y][x]);
				
				x = link[i], y = link[j];
				powerL += (S[x][y] + S[y][x]);
			}
		}

		answer = min(answer, abs(powerS - powerL));

	} while (next_permutation(tmp.begin(), tmp.end()));

	cout << answer;
	
	return 0;
}

