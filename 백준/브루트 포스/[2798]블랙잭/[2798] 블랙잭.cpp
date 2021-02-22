#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M; //카드의 개수, 합.
vector<int> cards;
vector<int> answer; //3장 뽑아서 구한 합 모든 경우에 대해 저장. 

void pick3Cards() {

	//nC3 모든 경우에 대해 합을 구함. answer에 저장 
	vector<int> tmp(N - 3, 0);
	for (int i = 0; i < 3; i++)  tmp.push_back(1);

	sort(tmp.begin(), tmp.end());
	do {
		int cnt = 0; int sum = 0;
		for (int i = 0; i < N; i++) {
			if (tmp[i] == 1) {
				cnt++;
				sum += cards[i];
			}

			if (cnt == 3) break;
		}

		answer.push_back(sum);

	} while (next_permutation(tmp.begin(), tmp.end()));
}

int main() {


	//입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int card;
		cin >> card;
		cards.push_back(card);
	}

	//3장 뽑아서 합을 구하기 
	pick3Cards();  // O(N * nC3) 

	//M에 가장 근접한 최대합 구하기
	sort(answer.begin(), answer.end(), greater<int>()); //내림차순 정렬
	for (auto e : answer) {
		if (e <= M) {
			cout << e;
			break;
		}
	}


	return 0;
}