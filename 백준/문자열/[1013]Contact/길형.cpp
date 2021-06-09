#include <vector>
#include <iostream>
#include <string>
#include <regex>
#define endl "\n"

using namespace std;

int testcase;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> testcase;

	regex number("((100+1+)|(01))+");

	while (testcase--)
	{
		string str;
		cin >> str;

		if (regex_match(str, number)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
