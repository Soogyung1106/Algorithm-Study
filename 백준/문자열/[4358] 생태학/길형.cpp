#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#define endl "\n"

using namespace std;

bool comp(const pair<string, int> &a, const pair<string, int> &b)
{
	return a.first < b.first;
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

	map<string, int> m;
	
	int count = 0;

	while (true)
	{
		string temp;
		getline(cin, temp);

		if (temp == "") break;
		else count++;

		if (!m.count(temp))
		{
			m.insert({ temp, 1 });
		}
		else
		{
			m[temp]++;
		}
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(),comp);

	cout << fixed;
	cout.precision(4);

	for (int i = 0; i < v.size(); i++)
	{
		double percent = round((((double(v[i].second) / double(count)) * 100.0)*10000.0)) / 10000.0;
		cout << v[i].first + " " << percent << endl;
	}

	return 0;
}
