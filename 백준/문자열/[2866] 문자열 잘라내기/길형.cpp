#include <vector>
#include <iostream>
#include <string>
#include <set>
#define endl "\n"

using namespace std;

int r, c;
string arr[1001];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> r >> c;

	for (int i = 1; i <= r; i++) 
	{
		cin >> arr[i];
	}

	int start = 1, end = r;

	while (start <= end) 
	{
		int mid = (start + end) / 2;
		set<string> s;
		bool check = true;

		for (int i = 0; i < c; i++) 
		{
			string temp = "";

			for (int j = mid; j <= r; j++) 
			{
				temp += arr[j][i];
			}

			if (s.find(temp) == s.end()) 
			{
				s.insert(temp);
			}
			else 
			{
				check = false;
				break;
			}
		}

		if (check) 
		{
			start = mid + 1;
		}
		else 
		{
			end = mid - 1;
		}
	}

	cout << start - 2;


	return 0;
}
