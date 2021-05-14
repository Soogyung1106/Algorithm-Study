#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	int n, s;
	cin >> n >> s;
	vector<int> number(n);

	for (auto& i : number)
	{
		cin >> i;
	}

	int sum = 0;
	int low = 0, high = 0;
	int answer = INF;

	while (low < n) 
	{

		if (sum < s && high < n)
		{
			sum += number[high++];
		}
		else
		{
			sum -= number[low++];
		}
		if (sum >= s)
		{
			answer = min(answer, high - low);
		}
	}

	if (answer == INF)
	{
		cout << 0 << "\n";
	}
	else
	{
		cout << answer << "\n";
	}

	return 0;
}
