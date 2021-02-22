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
	string str;
	cin >> str;

	int sum = 0;
	int temp = 0;
	bool flag = false;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (flag)sum -= temp;  // '-' 가 한번이라도 나온 후에는 전부 빼주기
			else sum += temp;        // '-' 가 나오기 전까지는 더해주기

			temp = 0;       // temp수를 다시 리셋
			if (str[i] == '-')flag = true;  // '-'가 나오면 flag를 true
		}
		else  //숫자가 연속해서 나오는동안은 한 수로 붙이기
		{
			temp *= 10;
			temp += str[i] - '0';
		}
	}

	//마지막 남은 숫자
	if (flag)sum -= temp;
	else sum += temp;

	cout << sum << endl;

	return 0;
}
