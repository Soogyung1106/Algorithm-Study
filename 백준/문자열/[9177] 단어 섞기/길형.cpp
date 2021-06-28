#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define endl "\n"

using namespace std;

int N;
string str1, str2, target;
bool visited[201][201];

bool dfs(int str1_idx,int str2_idx, int target_idx)
{
	if (target_idx == target.size()) return true;

	if (visited[str1_idx][str2_idx]) return false;

	visited[str1_idx][str2_idx] = true;

	if (target[target_idx] == str1[str1_idx] && target[target_idx] == str2[str2_idx])
	{
		return dfs(str1_idx + 1, str2_idx, target_idx + 1) || dfs(str1_idx, str2_idx + 1, target_idx + 1); // 이번에 배운 return case1||case2; 스킬
	}
	else if (target[target_idx] == str1[str1_idx])
	{
		return  dfs(str1_idx + 1, str2_idx, target_idx + 1);
	}
	else if (target[target_idx] == str2[str2_idx])
	{
		return  dfs(str1_idx, str2_idx + 1, target_idx + 1);
	}
	else return false;
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
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> str1 >> str2 >> target;

		memset(visited, false, sizeof(visited));
		str1 += ".";
		str2 += ".";

		cout << "Data set " << i << ": " << (dfs(0, 0, 0) ? "yes" : "no") << endl;
	}

	return 0;
}
