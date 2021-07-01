#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

vector<int> alphavet[26];
vector<int> v;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	int testcase;
	init();
	cin >> testcase;

	while (testcase--)
	{
		string w;
		int k;
		cin >> w;
		cin >> k;

		v.clear();
		for (int i = 0; i < 26; i++) alphavet[i].clear();
		for (int i = 0; i < w.size() ; i++) alphavet[w[i] - 'a'].push_back(i);

		for (int i = 0; i < 26; i++) 
		{
			if (alphavet[i].size() < k) continue;

			for (int j = 0; j + k - 1 < alphavet[i].size(); j++)
			{
				v.push_back(alphavet[i][j + k - 1] - alphavet[i][j] + 1);
			}
		}

		sort(v.begin(), v.end());

		if (v.size() == 0) cout << -1 << endl;
		else cout << v[0] << " " << v[v.size()-1] << endl;
	}

	return 0;
}
