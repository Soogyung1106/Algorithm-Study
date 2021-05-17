#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
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

	int N;
	cin >> N;

	queue<int> card;

	for (int i = 1; i < N + 1; i++)
	{
		card.push(i);
	}

	while (card.size() > 1)
	{
		card.pop();
		card.push(card.front());
		card.pop();
	}
	
	cout << card.front() << endl;

	return 0;
}
