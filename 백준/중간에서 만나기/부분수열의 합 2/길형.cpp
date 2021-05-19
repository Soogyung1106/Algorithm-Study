#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

int arr[40];
int N, S;
long long cnt;
vector<int> left_arr, right_arr;

void dfsLeft(int idx, int sum) 
{
	sum += arr[idx];
	if (idx >= N / 2) return;
	if (sum == S) cnt++;

	left_arr.push_back(sum);
	dfsLeft(idx + 1, sum - arr[idx]);
	dfsLeft(idx + 1, sum);
}

void dfsRight(int idx, int sum) 
{
	sum += arr[idx];
	if (idx >= N) return;
	if (sum == S) cnt++; 

	right_arr.push_back(sum);
	dfsRight(idx + 1, sum - arr[idx]);
	dfsRight(idx + 1, sum);
}

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];

	dfsLeft(0, 0);
	dfsRight(N / 2, 0);

	sort(left_arr.begin(), left_arr.end());
	sort(right_arr.begin(), right_arr.end());

	for (int i = 0; i < left_arr.size(); i++) 
	{
		int temp = S - left_arr[i];
		int lower = lower_bound(right_arr.begin(), right_arr.end(), temp) - right_arr.begin();
		int upper = upper_bound(right_arr.begin(), right_arr.end(), temp) - right_arr.begin();
		cnt += upper - lower;
	}

	cout << cnt;

	return 0;
}
