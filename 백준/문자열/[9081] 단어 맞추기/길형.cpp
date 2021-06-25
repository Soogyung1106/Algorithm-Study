#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
#define endl "\n"
#define MAX 101

using namespace std;

string str;
vector<string> answer;
set<string> candidate;
bool visited[MAX];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		string str, answer;
		int cnt = 0;

		cin >> str;

		do 
		{
			answer = str;
			if (++cnt == 2) break;
		} while (next_permutation(str.begin(), str.end()));

		cout << answer << endl;
	}

	return 0;
}
