#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <stack>
#define endl "\n"

using namespace std;

string str;
int zero_point;
int number_cnt = 0;

string Make_zero(int cnt)
{
	string result = "";
	string temp = ":0000";

	for (int i = 0; i < cnt; i++)
	{
		result += temp;
	}

	return result;
}

int main()
{
	cin >> str;

	string temp = "";

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ':')
		{
			if (temp != "") number_cnt++; 

			temp = "";
		}
		else
		{
			temp += str[i];

			if (i == str.size() - 1) number_cnt++;
		}
	}

	string zero_number = Make_zero(8 - number_cnt);

	zero_point = str.find("::"); // string type str.find()는 iter를 return한다. 만약 없을 경우 string::npos 를 반환한다.

	if (zero_point != string::npos)
	{
		str.erase(zero_point, 1);
		str.insert(zero_point, zero_number);

		if (str[0] == ':') str = str.substr(1, str.size() - 1);
		if (str[str.size() - 1] == ':') str = str.substr(0, str.size() - 1);
	}

	string result = "";
	temp = "";

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ':')
		{
			int temp_size = temp.size();

			//생략된 0을 넣는다
			for (int j = 0; j < 4 - temp_size; j++) temp = '0' + temp;

			result += temp;
			result += ':';

			temp = "";
		}
		else
		{
			temp += str[i];

			if (i == str.size() - 1)
			{
				int temp_size = temp.size();

				for (int j = 0; j < 4 - temp_size; j++)
				{
					temp = '0' + temp;
				}

				result += temp;
			}
		}
	}

	cout << result;

	return 0;
}
