#include <vector>
#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

string str;
int answer;
int alphabet[27];


void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void dfs(int idx, string now) 
{
	if (idx == str.size()) 
	{
		answer++;
		return;
	}

	for (int i = 0; i < 26; i++) 
	{
		if (alphabet[i] == 0) continue;
		if (now != "" && now[now.size() - 1] == (char)('a' + i)) continue;

		alphabet[i]--;
		dfs(idx + 1, now + (char)('a' + i));
		alphabet[i]++;
	}
}

int main()
{
	init();
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		alphabet[str[i] - 'a']++;
	}
		
	dfs(0, "");

	cout << answer << endl;

	return 0;
}
