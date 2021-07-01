#include <vector>
#include <iostream>
#include <string>
#include <map>
#define endl "\n"

using namespace std;

int n, m, k;
string str[10];
map<string, int> mp;

int dx[8] = { -1,1,0,0,-1,1,1,-1 };
int dy[8] = { 0,0,-1,1,1,1,-1,-1 };

void dfs(int x, int y, int pos, string sum)
{
	if (pos >= 5) 
	{
		return;
	}

	mp[sum] += 1;

	for (int i = 0; i < 8; i++) 
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0) nx = n - 1;
		if (nx >= n) nx = 0;
		if (ny < 0) ny = m - 1;
		if (ny >= m) ny = 0;

		dfs(nx, ny, pos + 1, sum + str[nx][ny]);
	}
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	string input = "";

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) cin >> str[i];
		
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dfs(i, j, 0, input + str[i][j]);
		}
			
	}

	while (k--)
	{
		string s;
		cin >> s;
		cout << mp[s] << endl;
	}

	return 0;
}
