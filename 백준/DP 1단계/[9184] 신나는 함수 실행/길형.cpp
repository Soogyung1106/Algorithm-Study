#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#define MAX 21
#pragma warning(disable:4996)

int check[MAX][MAX][MAX];

using namespace std;

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	if (check[a][b][c] != 0) 
		return check[a][b][c];

	if (a < b && b < c)
	{
		check[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return check[a][b][c];
	}
	else
	{
		check[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		return check[a][b][c];
	}
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	int a, b, c;

	while(true)
	{
		cin >> a >> b >> c;

		if(a == -1 && b == -1 && c == -1) break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c));
	}
	
	return 0;
}
