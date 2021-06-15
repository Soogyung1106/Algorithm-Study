//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string str;
int alpha[27], cnt;

void backTracking(string pre) {
	
	if (pre.size() == str.size()) { //기저조건
		cnt++;
		return;
	}

	//재귀 호출하면서 이전것 문자랑 같은지 다른지 판단...->같으면 종료 혹은 넘어가기 
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0) continue;
		if (pre != "" && pre.back() == (char)('a'+i)) continue;
		
		alpha[i]--;
		backTracking(pre + (char)('a' + i));
		alpha[i]++; //복귀
	}
}

int main() {

	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input1.txt", "r", stdin);
	cin >> str;

	for (int i = 0; i < str.size(); i++)
		alpha[str[i] - 'a']++;

	backTracking("");

	cout << cnt <<'\n';

	return 0;
}
