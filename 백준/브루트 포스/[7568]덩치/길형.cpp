#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	int n;
	vector<pair<int, int>> info;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int w, h;
		cin >> w >> h;
		info.push_back(make_pair(w, h));
	}

	for (int i = 0; i < n; i++)
	{
		int count = 1;
		for (int j = 0; j < n; j++)
		{
			if (info[i].first < info[j].first && info[i].second < info[j].second)
			{
				count++;
			}
		}
		cout << count << " ";
	}

	return 0;
}
