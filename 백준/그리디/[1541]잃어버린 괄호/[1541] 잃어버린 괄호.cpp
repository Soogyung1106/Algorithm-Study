#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

vector<int> number; //문자열
vector<char> op; //연산자

void parsing(string str) {

	string strnum;
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i]))
			strnum += str[i];
		else {
			number.push_back(stoi(strnum));
			strnum = "";//초기화
			op.push_back(str[i]);
		}
	}
	number.push_back(stoi(strnum)); //맨 마지막 숫자
}

int main() {

	//입력
	string str;
	cin >> str;

	//파싱
	parsing(str);

	//(+) 우선 연산
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '+') {
			op.erase(op.begin() + i);
			number[i] += number[i + 1];
			number.erase(number.begin() + i + 1);
			i--;
		}
	}

	//(-) 연산
	for (int i = 0; i < op.size(); i++) {
		op.erase(op.begin() + i);
		number[i] -= number[i + 1];
		number.erase(number.begin() + i + 1);
		i--;
	}

	cout << number[0]; //모두 계산 후 number에 최종값 한 개 들어있음.

	return 0;
}