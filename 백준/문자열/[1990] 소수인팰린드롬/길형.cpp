#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define endl "\n"

using namespace std;

int a, b;
vector<int> v;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void make_palin(void)
{
	for (int i = 1; i <= 10000; i++)
	{
		string s = to_string(i);
		
		if (s.size() == 1)
		{
			int n = stoi(s + s);
			if (a <= i && i <= b) v.push_back(i);
			if (a <= n && n <= b) v.push_back(n);
		}
		else
		{
			string rs1 = s;
			string rs2 = s;
			rs2.pop_back();
			reverse(rs1.begin(), rs1.end());
			reverse(rs2.begin(), rs2.end());

			int n1 = stoi(s + rs1);
			int n2 = stoi(s + rs2);
			if (a <= n1 && n1 <= b) v.push_back(n1);
			if (a <= n2 && n2 <= b) v.push_back(n2);
		}
	}
}

bool chekc_prime(int num) 
{
	if (num < 2) return false;
	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

int main()
{
	init();
	cin >> a >> b;

	make_palin();

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) if (chekc_prime(v[i])) cout << v[i] << endl;

	cout << "-1" << endl;

	return 0;
}
