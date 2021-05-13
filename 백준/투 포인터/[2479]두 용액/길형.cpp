#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();

	int  N;
	vector<int> pH;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		pH.push_back(temp);
	}

	sort(pH.begin(), pH.end());

	int start = 0; 
	int end = N - 1; 
	int min = INT_MAX; 
	int answer_start = pH[0], answer_end = pH[N-1];

	while (start < end) 
	{
		int sum = pH[start] + pH[end];

		if (min > abs(sum)) {
			min = abs(sum);
			answer_start = pH[start];
			answer_end = pH[end];

			if (sum == 0)
				break;
		}

		if (sum < 0)
			start++;
		else
			end--;
	}

	cout << answer_start << " " << answer_end;

	return 0;
}
