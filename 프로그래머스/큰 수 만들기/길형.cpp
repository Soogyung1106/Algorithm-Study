#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) 
{
	string answer = "";

	int num_size = number.size() - k;
	int start = 0;

	for (int i = 0; i < num_size; i++) 
	{
		char max_number = number[start];
		int max_index = start;

		for (int j = start; j <= k + i; j++) 
		{
			if (max_number < number[j]) 
			{
				max_number = number[j];
				max_index = j;
			}
		}
		start = max_index + 1;
		answer += max_number;
	}

	return answer;
}
