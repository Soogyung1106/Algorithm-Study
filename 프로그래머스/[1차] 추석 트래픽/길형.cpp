#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines)
{
	int answer = 0;

	int size = lines.size();
	vector<int> end_time(size, 0); // 처리 끝난 시간
	vector<int> start_time(size, 0); // 처리 시작 시간

	for (int i = 0; i < size; ++i) 
	{
		end_time[i] += 3600000 * stoi(lines[i].substr(11, 2));
		end_time[i] += 60000 * stoi(lines[i].substr(14, 2));
		end_time[i] += (int)(1000 * stod(lines[i].substr(17, 6)));

		string temp = lines[i].substr(24);
		temp.pop_back();

		start_time[i] = end_time[i] - (int)(1000 * stod(temp)) + 1;
	}

	for (int i = 0; i < size; ++i) 
	{
		int cnt = 0;

		for (int j = i; j < size; ++j) 
		{
			if (end_time[j] - end_time[i] >= 4000) 
			{
				break;
			}
			if (start_time[j] <= end_time[i] + 999) 
			{
				++cnt;
			}
		}
		answer = max(answer, cnt);
	}

	return answer;
}
