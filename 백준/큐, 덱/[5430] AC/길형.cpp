#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <deque>
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
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++)
	{
		string func;
		cin >> func;

		int N;
		cin >> N;

		string arr;
		cin >> arr; //배열 입력

		deque<int> dq; //덱
		string temp; //두 자릿수 이상 숫자를 위하여

		for (int i = 0; i < arr.length(); i++)
		{ 
			if (arr[i] == '[') continue;
			else if ('0' <= arr[i] && arr[i] <= '9') temp += arr[i];
			else if (arr[i] == ',' || arr[i] == ']')
			{
				if (!temp.empty())
				{
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool print = true; //error가 아닐 경우 true
		bool left = true; //뒤집어져있지 않으면 true

		for (int i = 0; i < func.length(); i++)
		{
			if (func[i] == 'R') left = !left;
			else
			{
				if (dq.empty())
				{
					print = false;
					cout << "error" << endl;
					break;
				}
				else
				{
					if (left) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		if (print)
		{
			if (left)
			{
				cout << "[";

				while (!dq.empty())
				{
					cout << dq.front();
					dq.pop_front();

					if (!dq.empty()) cout << ",";
				}

				cout << "]" << endl;
			}
			else
			{
				cout << "[";

				while (!dq.empty())
				{
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]" << endl;
			}
		}
	}

	return 0;
}
