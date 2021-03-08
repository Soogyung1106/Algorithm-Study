/*
문제
N개 시험장, i번 시험장의 응시자 수 시험장[i] = A명, 총감독관 한 시험장에서 B명까지 감시 가능, 부감독관은 C명
각 시험장에는 총감독관은 1명, 부감독관은 여러명
이때 필요한 감독관(총감독관 + 부감독관)의 수

입력
첫째 줄에 시험장의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 각 시험장에 있는 응시자의 수 Ai (1 ≤ Ai ≤ 1,000,000)가 주어진다.

셋째 줄에는 B와 C가 주어진다. (1 ≤ B, C ≤ 1,000,000)

출력
각 시험장마다 응시생을 모두 감독하기 위해 필요한 감독관의 최소 수를 출력한다.
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

vector<int> A;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();

	int N,B, C;;
	long long sum = 0;

	cin >> N;

	for(int i = 0 ; i < N ; i++)
	{
		int temp;
		cin >> temp;

		A.push_back(temp);
	}

	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;

		A[i] -= B;
		sum++;

		if (A[i] <= 0) continue;

		temp = A[i] / C;
		A[i] -= temp * C;

		sum += temp;
		if (A[i] > 0) sum++;
	}

	cout << sum << endl;

	return 0;
}
