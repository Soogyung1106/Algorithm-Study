#include <vector>
#include <iostream>
#include <string>
#include <regex>
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
	string str;
	cin >> str;

	regex number("(100+1+|01)+");

	if (regex_match(str, number)) cout << "SUBMARINE" << endl;
	else cout << "NOISE" << endl;

	return 0;
}
