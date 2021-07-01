#include <vector>
#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

string str;

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
	
	string answer = "";
	string number = "";
	int x_idx = 0;

	if (str[0] == '-')
	{
		number += "-";
	}
	else if (str[0] == '0')
	{
		cout << "W" << endl;
		return 0;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'x')
		{
			x_idx = i;
			break;
		}
	}

	int i = 0;
	string temp = "";

	if (number == "-") i = 1;



	if (x_idx) // x가 일차식일 경우, x가 있을 경우.
	{
		for (i; i < x_idx; i++) temp += str[i];

		number += temp;
		number = to_string(stoi(number) / 2);

		if (number == "1") number = "";
		else if (number == "-1") number = "-";

		answer += (number + "xx");

		if (x_idx + 1 != str.size())
		{
			answer += str[x_idx + 1];

			string temp_num = "";

			for (int i = x_idx + 2; i < str.size(); i++) temp_num += str[i];

			if (temp_num == "1") answer += "x";
			else if (temp_num == "0") answer.pop_back();
			else answer += (temp_num + "x");
		}
	}
	else
	{
		for (i; i < str.size(); i++) number += str[i];

		if (number == "1") number = "";
		else if (number == "-1") number = "-";

		answer += (number + "x");
	}

	cout << answer + "+W" << endl;

	return 0;
}
