#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 300001

using namespace std;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main() 
{
	int D, N; 
	cin >> D >> N;

	long dough[MAX];
	long oven[MAX];

	long min_dough = LONG_MAX;
	long min_oven = LONG_MAX;

	long blocked = D + 1;

	for (int i = 1; i <= D; i++) 
	{
		long temp; 
		cin >> temp;

		min_oven = min(temp, min_oven);
		oven[i] = min_oven;
	}

	for (int i = 1; i <= N; i++) 
	{
		cin >> dough[i];

		min_dough = min(dough[i], min_dough);
	}

	for (int i = 1; i <= N; i++) 
	{
		if (i != 1 && dough[i] <= dough[i - 1]) 
		{
			blocked--;
		}
		else 
		{
			for (int j = blocked - 1; j >= 1; j--) 
			{
				if (oven[j] < dough[i]) 
				{
					blocked--;
				}
				else break;
			}
			blocked--;
		}
	}

	if (blocked <= 0) blocked = 0;

	cout << blocked;

	return 0;
}
