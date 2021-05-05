#include <string>
#include <vector>
#include <set>
#define MAX 10
using namespace std;

vector<int> candidate[MAX];
int visit[MAX];
set<string> s;

void dfs(int index, int N)
{
	if (index == N) 
	{
		string temp = "";

		for (int i = 0; i < 10; i++)
		{
			if (visit[i] == 1) temp += to_string(i);
		}
			
		s.insert(temp);
		return;
	}

	for (int j = 0; j < candidate[index].size(); j++) 
	{
		int now = candidate[index][j];

		if (visit[now] == 1) continue;
		visit[now] = 1;
		dfs(index + 1, N);
		visit[now] = 0;
	}
}


int solution(vector<string> user_id, vector<string> banned_id) 
{
	int answer = 0;

	for (int i = 0; i < banned_id.size(); i++)
	{
		int id_size = banned_id[i].size();

		for (int j = 0; j < user_id.size(); j++)
		{
			bool check = true;
			// 불량 사용자와 사용자 아이디 길이 비교
			if (banned_id[i].size() != user_id[j].size()) continue;

			for (int index = 0; index < user_id[j].size(); index++)
			{
				if (banned_id[i][index] == '*') continue;
				else if (banned_id[i][index] == user_id[j][index]) continue;
				else
				{
					check = false;
					break;
				}
			}
			if (check) candidate[i].push_back(j);
		}
	}

	dfs(0, banned_id.size());
	answer = s.size();

	return answer;
}
