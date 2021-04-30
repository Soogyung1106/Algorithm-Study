#include <string>
#include <vector>
#include <map>

using namespace std;

void Init(map<string,int> &dictionary)
{
	for (int i = 0; i < 26; i++)
	{
		dictionary[string(1, 'A' + i)] = i + 1;
	}
}

vector<int> solution(string msg) 
{
	vector<int> answer;
	map<string, int> dictionary;

	Init(dictionary);

	string w, c;
	int alphabet = 27;
	int cnt = 1;
	int i;

	for (i = 0; i < msg.length(); i++)
	{
		w = msg.substr(i, cnt);

		if (i + cnt >= msg.length()) break; // 범위 초과하면

		c = msg.substr((i + cnt), 1);

		if (dictionary[w + c]) //사전의 해당 단어가 있으면
		{
			cnt++;
			i--;
		}
		else 
		{
			answer.push_back(dictionary[w]);
			dictionary[w + c] = alphabet++;
			i += cnt - 1;
			cnt = 1;
		}
	}
	answer.push_back(dictionary[msg.substr(i, cnt)]);

	return answer;
}
