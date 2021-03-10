#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 20;

int main() {

	//입력
	int N;
	cin >> N;

	vector<long long> num(N); //연산한 결과를 num에 동시에 갱신할 것이기 떄문에 long long
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int op[4];
	for (int i = 0; i < 4; i++)
		cin >> op[i]; //0 0 1 0

	vector<int> tmpOp; //+: 0, -: 1, x: 2, %: 3
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < op[i]; j++)
			tmpOp.push_back(i);

	sort(tmpOp.begin(), tmpOp.end());


	//연산자 tmpOp 배열을 가지고 만들 수 있는 모든 경우의 수 구하기
	long long MIN = 9876543210, MAX = -9876543210;
	do {
		vector<long long> tmpNum = num; //num 배열 복사

		for (int i = 0; i < N - 1; i++) {
			switch (tmpOp[i]) {
			case 0: //+
				tmpNum[i + 1] += tmpNum[i];
				break;
			case 1: //-
				tmpNum[i + 1] = tmpNum[i] - tmpNum[i + 1];
				break;
			case 2: //x
				tmpNum[i + 1] = tmpNum[i + 1] * tmpNum[i];
				break;
			case 3: //%
				tmpNum[i + 1] = tmpNum[i] / tmpNum[i + 1];
				break;
			}
		}

		//tmpNum의 맨 마지막 요소에 연산 결과 최종적으로 저장
		MIN = min(MIN, tmpNum[N - 1]);
		MAX = max(MAX, tmpNum[N - 1]);

	} while (next_permutation(tmpOp.begin(), tmpOp.end()));

	//출력
	cout << MAX << '\n' << MIN << '\n';

	return 0;
}