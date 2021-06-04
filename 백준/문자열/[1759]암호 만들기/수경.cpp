#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
char arr[20];

void backTracking(int pos, string str, int ja, int mo)
{
	//종료조건
	if (str.size() == L){
		if (ja < 2 || mo < 1) return; //예외처리(모음과 자음의 개수 조건)
		cout << str << '\n';
	}

	//탐색
	for (int i = pos; i < C; i++){
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			backTracking(i + 1, str + arr[i], ja, mo + 1);
		else
			backTracking(i + 1, str + arr[i], ja + 1, mo);
	}
}

int main(){

	//입력
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> arr[i];

	sort(arr, arr + C); //사전순 정렬 

	//탐색
	backTracking(0, "", 0, 0);
	return 0;
}
