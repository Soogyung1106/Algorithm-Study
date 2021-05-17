#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <deque>
#define endl "\n"

using namespace std;

int N;
deque<int> q;

void push(int number)
{
	q.push_back(number);

	return;
}

void pop(void)
{
	if (q.empty())
	{
		cout << -1 << endl;
	}
	else
	{
		cout << q.front() << endl;
		q.pop_front();
	}

	return;
}

void front(void)
{
	if (q.empty())
	{
		cout << -1 << endl;
	}
	else
	{
		cout << q.front() << endl;
	}

	return;
}

void back(void)
{
	if (q.empty())
	{
		cout << -1 << endl;
	}
	else
	{
		cout << q.back() << endl;
	}

	return;
}

void empty(void)
{
	if (q.empty())
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	return;
}

void size(void)
{
	cout << q.size() << endl;
}

void function_queue(string s)
{
	if (s == "pop") pop();
	else if (s == "size") size();
	else if (s == "front") front();
	else if (s == "back") back();
	else if (s == "empty") empty();
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

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			string temp;
			cin >> temp;
			push(stoi(temp));
		}
		else function_queue(s);
		

	}

	return 0;
}
