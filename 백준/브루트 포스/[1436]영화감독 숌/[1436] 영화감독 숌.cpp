#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;

	int cnt = 0; int num = 666;
	while (1) {

		//num에 6이 3번 연속해서 들어갔는지 카운트 
		string str = to_string(num); 
		if (str.find("666") != string::npos) cnt++;
	
		if (cnt == n) break; //종료 조건
		
		num++;
	}
	
	cout << num;

	return 0;
}
