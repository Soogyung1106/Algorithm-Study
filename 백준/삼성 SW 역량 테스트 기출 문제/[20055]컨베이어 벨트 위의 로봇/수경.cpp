#include <iostream>
#include <queue>

#define MAX 220
#define endl "\n"
using namespace std;

int N, K, Start, End, Cnt, Answer;
int Belt[MAX]; //컨베이어 벨트의 내구도
bool Visit[MAX]; //로봇이 벨트 위치 선점 여부 체크(이미 다른 로봇이 올라와 있는 경우 이동 x) 
queue<int> Robot; //로봇의 벨트 위 위치(올라온 순서대로 접근 > 큐로 선언)

//컨베이어 벨트를 이동시킬 때 벨트는 고정하고 "인덱스"를 움직여서 벨트의 움직임 계산
void Move_Belt() {
	//1 2 3 4 5 6 > 한 칸 이동시킨다면
	Start--; //0
	End--; //5
	if (Start < 1) Start = 2 * N; //start의 위치는 0 -> 6 
}

void Move_Robot(){

	//로봇이 하나도 올라와 있지 않다면 이 함수를 skip.
	for (int i = 0; i < Robot.size(); i++) 
	{
		int Cur = Robot.front(); //가장 먼저 올라온 로봇의 위치 
		Visit[Cur] = false; //로봇이 올라와 있다고 체크
		Robot.pop();

		if (Cur == End) continue; //?

		int Next = Cur + 1; //움직일 다음 위치
		if (Next > 2 * N) Next = 1; //"올라가야 하는 위치"라면.

		//0이 아니고 로봇이 선점 안 했다면.
		if (Belt[Next] >= 1 && Visit[Next] == false) { 
			Belt[Next]--; //내구도 감소
			if (Belt[Next] == 0) Cnt++; //내구도 0의 개수 카운트 
			if (Next == End) continue;
			Visit[Next] = true; //점유 표시
			Robot.push(Next); 

		}else{
			Visit[Cur] = true;
			Robot.push(Cur);
		}
	}
}

void Make_Robot()
{
	//"올라가는 위치"가 선점되어 있지 않고 0이 아니라면.
	if (Visit[Start] == false && Belt[Start] >= 1) {
		Visit[Start] = true;
		Belt[Start]--;
		Robot.push(Start);

		if (Belt[Start] == 0) Cnt++;
	}
}

void Solution()
{
	Start = 1;
	End = N;

	while (Cnt < K)
	{
		Answer++; 

		Move_Belt(); //벨트 한 칸 회전
		Move_Robot(); //로봇 이동 
		Make_Robot(); //로봇 올리기 
	}
	cout << Answer << endl; //종료될 때 진행 중이던 단계
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("Input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) cin >> Belt[i]; //컨베이어 벨트의 내구도 입력 

	Solution();

	return 0;
}

