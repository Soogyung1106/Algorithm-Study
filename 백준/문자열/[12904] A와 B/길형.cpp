#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	string s, t;
	cin >> s >> t;

	while (t.size() > s.size()) 
	{
		if (t.back() == 'A')
		{
			t.pop_back();
		}
		else 
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}

	if (s == t) cout << 1 << endl;
	else cout << 0 << endl;

	return 0;
}
