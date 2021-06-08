#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#define endl "\n"
#define MAX 1003002

using namespace std;

bool prime_array[MAX];
int N;

void prime_check(void) // 소수찾기
{
	memset(prime_array, true, sizeof(prime_array));

	prime_array[0] = prime_array[1] = false;

	for (int i = 2; i <= MAX; i++)
	{
		for (int j = 2; j*j <= i; j++) 
		{
			if (i % j == 0) 
			{
				prime_array[i] = false;
				break;
			}
		}
	}
}

bool number_check(int N) // 팰린드롬 체크
{
	string s = to_string(N);
	int size = s.size();

	for (int i = 0, j = size - 1; i < size, j >= 0; i++, j--) 
	{
		if (s[i] != s[j]) return false;
	}
	return true;
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
	cin >> N;
	prime_check();

	for (int i = N; i <= MAX; i++)
	{
		if (prime_array[i] && number_check(i))
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}
