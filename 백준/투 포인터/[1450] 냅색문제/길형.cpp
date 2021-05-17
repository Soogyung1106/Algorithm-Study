#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

long long N, C, W[31], answer;
vector<long long> group1;
vector<long long> group2;

void dfs(int start, int end, vector<long long>& v, long long sum)
{
	if (start > end)
	{
		v.push_back(sum);
		return;
	}
	else
	{
		dfs(start + 1, end, v, sum);
		dfs(start + 1, end, v, sum + W[start]);
	}
}

// N : 2 , C : 1
// dfs(0, 1, group1, 0)
// dfs(1, 1, group2, 0)
// 1 1 group1, 0
// 2 1 gruop1, 0
// if(start > end) -> true group1 = {0};
// 2 1 group1 0+1
// if(start > end) -> true group1 = {0, 1};

int main()
{
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> W[i];
	}

	// 반으로 나눠서 경우의수 저장  
	dfs(0, N / 2, group1, 0); // 0 ~ N/2 까지 경우의 수 찾기.
	dfs(N / 2 + 1, N - 1, group2, 0); // N/2 + 1 ~ N까지 경우의 수 찾기.
	sort(group2.begin(), group2.end());


	for (int i = 0; i < group1.size(); i++)
	{
		answer += upper_bound(group2.begin(), group2.end(), C - group1[i]) - group2.begin();

		/*
		upper_bound 란?
		- lower_bound와 마찬가지로 이진탐색(Binary Search)기반의 탐색법 입니다.
		- 이진탐색(Binary Search)기반이므로 배열이나 리스트가 오름차순으로 정렬 되어있어야 합니다.
		- upper_bound는 key값을 초과하는 가장 첫 번째 원소의 위치를 구하는 것 입니다.
		- 같은 원소가 여러개 존재 해도 항상 유일한 해를 구할 수 있습니다.
		- 구간이 [start, end]인 배열이 있을때, 중간위치의 index를 mid 라고 하면, arr[mid-1] <= key 이면서 arr[mid] > key 인 최소의 m 값을 찾으면 됩니다. (m>=2)
		- upper_bound에서 기억해야 할 것은 (같은 값이 아닌) key 값을 초과하는 가장 첫번째 원소의 위치 라는 것 입니다.
		*/
	}

	cout << answer << endl;

	return 0;
}
