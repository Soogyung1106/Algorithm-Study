#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#define endl "\n"

using namespace std;

void trans_number(string str)
{
	unordered_map<int, string> map1, map10, map100, map1000;
	int digit = 1;
	stack<string> st;

	map1.insert({ 0, "" });
	map1.insert({ 1, "I" });
	map1.insert({ 2, "II" });
	map1.insert({ 3, "III" });
	map1.insert({ 4, "IV" });
	map1.insert({ 5, "V" });
	map1.insert({ 6, "VI" });
	map1.insert({ 7, "VII" });
	map1.insert({ 8, "VIII" });
	map1.insert({ 9, "IX" });

	map10.insert({ 0, "" });
	map10.insert({ 1, "X" });
	map10.insert({ 2, "XX" });
	map10.insert({ 3, "XXX" });
	map10.insert({ 4, "XL" });
	map10.insert({ 5, "L" });
	map10.insert({ 6, "LX" });
	map10.insert({ 7, "LXX" });
	map10.insert({ 8, "LXXX" });
	map10.insert({ 9, "XC" });

	map100.insert({ 0, "" });
	map100.insert({ 1, "C" });
	map100.insert({ 2, "CC" });
	map100.insert({ 3, "CCC" });
	map100.insert({ 4, "CD" });
	map100.insert({ 5, "D" });
	map100.insert({ 6, "DC" });
	map100.insert({ 7, "DCC" });
	map100.insert({ 8, "DCCC" });
	map100.insert({ 9, "CM" });


	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (digit == 1)
		{
			string value = map1[str[i] - '0'];
			st.push(value);
		}
		else if (digit == 10)
		{
			string value = map10[str[i] - '0'];
			st.push(value);
		}
		else if (digit == 100)
		{
			string value = map100[str[i] - '0'];
			st.push(value);

		}
		else if (digit == 1000)
		{
			int value = str[i] - '0';
			for (int j = 0; j < value; j++)
			{
				st.push("M");
			}

		}
		digit *= 10;
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
	cout << endl;
}
void trans_string(string str)
{
	unordered_map<char, int> um = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

	unordered_map<string, int> um_2 = {{"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};

	int result = 0;
	for (int i = 0; i < str.size() - 1; i++) 
	{
		if (um_2[str.substr(i, 2)] > 0) 
		{
			result += um_2[str.substr(i, 2)];
			i++;
		}
		else 
		{
			result += um[str[i]];
		}
	}

	if (str.size() == 1 || um_2[str.substr(str.size() - 2, 2)] == 0) 
	{
		result += um[str.back()];
	}

	cout << result << endl;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	map<int, string> s;
	int t;
	cin >> t;

	while (t--)
	{
		string str;
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9')
		{
			trans_number(str);
		}
		else
		{
			trans_string(str);
		}

	}

	return 0;
}
