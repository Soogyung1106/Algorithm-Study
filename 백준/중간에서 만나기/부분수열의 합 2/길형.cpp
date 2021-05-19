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
	if (sum == S) cnt++; // 만약 S를 만들 수 있다면 cnt++을 해준다

	left_arr.push_back(sum);
	dfsLeft(idx + 1, sum - arr[idx]);
	dfsLeft(idx + 1, sum);
}

void dfsRight(int idx, int sum) 
{
	sum += arr[idx];
	if (idx >= N) return;
	if (sum == S) cnt++; // 만약 S를 만들 수 있다면 cnt++을 해준다

	right_arr.push_back(sum);
	dfsRight(idx + 1, sum - arr[idx]);
	dfsRight(idx + 1, sum);
}

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];

	// 벡터 left_arr,right_arr 에 반으로 나눈 각 배열에 대한 만들 수 있는 모든 부분집합의 합들을 미리 구해놓는다
	dfsLeft(0, 0);
	dfsRight(N / 2, 0);

	// 이분탐색을 이용하기 위해서 미리 정렬을 해둔다
	sort(left_arr.begin(), left_arr.end());
	sort(right_arr.begin(), right_arr.end());

	// 찾고자하는 값의 갯수를 이분탐색을 이용해서 구한다
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
