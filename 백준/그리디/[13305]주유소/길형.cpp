#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 100001
#pragma warning(disable:4996)

using namespace std;

//long long price[MAX];
//long long dist[MAX];

int main(void)
{
	freopen("input.txt", "r", stdin);

	long long n = 0;
	long long sum = 0;
	vector<long long> dist;
	vector<long long> price;
	
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		long long temp;
		cin >> temp;
		dist.push_back(temp);
	}

	for (int i = 0; i < n; i++) 
	{ 
		long long temp;
		cin >> temp;
		price.push_back(temp);
	}

	long long max_price = *max_element(price.begin(),price.end()); // 가격 중 가장 높은 것으로 일단 초기화

	for (int i = 0; i < n; i++)
	{
		if (max_price > price[i]) // 설정된 최대값보다 price[i]가 더 저렴하면 여기서 주유해야함
		{
			max_price = price[i];
		}
		sum += max_price * dist[i];
	}

	cout << sum << endl;

	return 0;
}
