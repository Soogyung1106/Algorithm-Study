#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
#define endl "\n"

using namespace std;

bool prime[100001];
bool visited[100001];
int max_num;
string str;

void prime_check(int len)
{
	int num = 0;

	for (int i = 0; i < str.size() - len; i++)
	{
		num = stoi(str.substr(i, len));

		if (num > 100000) continue;
		if (visited[num]) continue;

		visited[num] = true;
		if (!prime[num]) max_num = max(num, max_num);
	}
}

void find_prime(void)
{
	prime[0] = true;
	prime[1] = true;

	for (int i = 2; i*i <= 100000; i++)
	{
		if (prime[i]) continue;

		for (int j = i + i; j <= 100000; j += i)
		{
			prime[j] = true;
		}
	}
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
	find_prime();

	while (1)
	{
		cin >> str;

		if (str == "0") break;

		max_num = 0;
		int size = 0;

		memset(visited, false, sizeof(visited));

		if (str.size() > 6) size = 6;
		else size = str.size();

		for (int i = 1; i <= size ; i++)
		{
			prime_check(i);
		}

		cout << max_num << endl;
	}
	
	return 0;
}
