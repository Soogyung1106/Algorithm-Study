#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 20

using namespace std;

int N, S;
int answer;
int arr[MAX];

void dfs(int idx, int sum)
{
	sum += arr[idx];

	if (idx >= N) return;
	if (sum == S) answer++;

	dfs(idx + 1, sum - arr[idx]);
	dfs(idx + 1, sum);

}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	dfs(0, 0);

	cout << answer << endl;

	return 0;
}
