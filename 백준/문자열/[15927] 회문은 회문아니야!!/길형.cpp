#include <vector>
#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

string str;

bool answer = false;
bool palin = false;

int check_palin(string s)
{
	int size = s.size();

	for (int i = 0; i < size / 2; i++) // 팰린드롬 체크
	{
		if (s[i] != s[size - i - 1]) return size;
	}

	for (int i = 1; i < size; i++) 
	{
		if (s[0] != s[i]) return size - 1; // 전체 같은 문자인지 체크
	}

	return -1;
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

	cout << check_palin(str);

	return 0;
}
