#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

string str;
char ch[100000];

void chage_str(void)
{
	for (int i = 0; i < str.size()-1; i++)
	{
		if (str[i] < str[i + 1])
		{
			reverse(str.begin(), str.begin() + i + 1);
			reverse(str.begin(), str.begin() + i + 2);
		}
	}

	reverse(str.begin(), str.end());
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
	cin >> str;

	if(str.size() != 1)
		chage_str();

	cout << str << endl;
	return 0;
}
