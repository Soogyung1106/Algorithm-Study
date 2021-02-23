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
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int N;
	int count = 0;
	int title = 665;
	string temp;

	cin >> N;

	while (title++) 
	{
		temp = to_string(title);

		if (temp.find("666") != string::npos)  // string.find( ) 찾으면 해당 위치의 index를 반환, 없으면 -1(string::npos) 반환
		{
			++count;
		}

		if (count == N)
		{
			cout << title << endl;
			break;
		}
	}

	return 0;
}
