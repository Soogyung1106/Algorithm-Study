#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 1001
#pragma warning(disable:4996)

using namespace std;


int main(void)
{
	freopen("input.txt", "r", stdin);
	int n = 0;
	int sum = 0;
	cin >> n;

	vector<int> atm(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> atm[i];
	}

	sort(atm.begin(), atm.end(), less<int>());

	for (int i = 0; i < n; i++)
	{
		sum += atm[i] * (n - i);
	}

	cout << sum;

	return 0;
}
