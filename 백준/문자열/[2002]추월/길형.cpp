#include <vector>
#include <iostream>
#include <string>
#include <map>
#define endl "\n"
#define MAX 1001

using namespace std;

bool check[MAX];
int car[MAX];
map<string, int> m;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	check[0] = false;

	int num;
	cin >> num;
	
	string str;

	for (int i = 0; i < num; i++) 
	{
		cin >> str;
		m[str] = i;
	}

	for (int i = 0; i < num; i++) 
	{
		cin >> str;
		int order = m[str];
		car[i] = order;
	}

	int overtaking = 0;

	for (int i = 0; i < num - 1; i++) 
	{
		for (int j = i + 1; j < num; j++) 
		{
			if (car[i] > car[j]) 
			{
				overtaking++;
				break;
			}
		}
	}

	cout << overtaking << endl;

	return 0;
}
