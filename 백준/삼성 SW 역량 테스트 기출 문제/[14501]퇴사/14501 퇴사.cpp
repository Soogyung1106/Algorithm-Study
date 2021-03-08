#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 15 + 1;
vector<int> T(MAX); //소요일 
vector<int> P(MAX); //수익 
int answer = 0; //최대 수익
int N; //최대 날짜수

void bruteForce(int start, int profit) {
	//인자: 그 다음 상담 날짜, 그 날 전까지 번 수익
	//시작일을 기준으로 그 날 상담을 시작했을 경우와 안 하고 건너뛸 경우를 고려해. 최대 수익 갱신
	
	//기저조건
	if(start > N + 1)return;
	if (start == N + 1){
		answer = max(profit, answer);
		return;
	}

	//퇴사날짜를 넘어가지 않는다면.
	if (start + T[start] - 1 <= N)
		bruteForce(start + T[start], profit+P[start]); //start 날짜 당일에 상담할 경우 
	if(start <=N )
		bruteForce(start+1, profit); //스킵할 경우
}


int main() {
	
	cin >> N;
	for (int i = 1; i <= N;i++) 
		cin >> T[i] >> P[i];
	
	bruteForce(1, 0); //상담 시작일, 현재까지의 수익
	
	cout << answer; //갱신된 최대 수익 출력

	return 0;
}