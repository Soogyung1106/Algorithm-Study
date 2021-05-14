#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> primes;
vector<bool> check;

void MakePrime(void) // 에라토스테네스의 체
{
	for (int i = 2; i*i <= n; i++)
	{
		if (!check[i]) continue;

		for (int j = i * i; j <= n; j += i)
		{
			check[j] = false;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (check[i]) primes.push_back(i);
	}
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	cin >> n;
	
	check.resize(n + 1, true);

	MakePrime();

	int answer = 0;
	int sum = 0;
	int low = 0, high = 0;

	while (true) 
	{
		if (sum >= n) // n보다 sum(소수의 합)이 같거나 큰 경우
		{
			sum -= primes[low++];
		}
		else if (high == primes.size()) 
		{
			break;
		}
		else // n보다 sum(소수의 합)이 작은 경우
		{
			sum += primes[high++];
		}

		if (sum == n) answer++;
	}

	cout << answer;

	return 0;
}
