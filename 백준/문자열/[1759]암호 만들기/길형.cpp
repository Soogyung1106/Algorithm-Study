#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int L, C;
vector<char> alphabet;

void dfs(int idx, int length, int ja, int mo, string str) 
{
	if (length == L) 
	{
		if (ja < 2 || mo < 1) return; // 자음은 최소 2개, 모음은 최소 1개 이상
		cout << str << endl;

		return;
	}
	
	if (idx == C) return; // idx 가 끝

	if (alphabet[idx] == 'a' || alphabet[idx] == 'e' || alphabet[idx] == 'i' || alphabet[idx] == 'o' || alphabet[idx] == 'u')
	{
		dfs(idx + 1, length + 1, ja, mo + 1, str + alphabet[idx]);
	}
	else
	{
		dfs(idx + 1, length + 1, ja + 1, mo, str + alphabet[idx]);
	}
			
	dfs(idx + 1, length, ja, mo, str); //현재 알파벳을 선택하지 않고 넘어가는 경우 
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
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		char temp;
		cin >> temp;

		alphabet.push_back(temp);
	}

	sort(alphabet.begin(), alphabet.end());

	dfs(0, 0, 0, 0, "");

	return 0;
}
