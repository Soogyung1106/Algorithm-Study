#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<int>());
    
    while(!people.empty())
    {
        int first = people.front();
        int last = people.back();
        
        if(people.size() == 1)
        {
            answer++;
            break;
        }
        
        if(first + last <= limit)
        {
            people.erase(people.begin());
            people.pop_back();
        }
        else
        {
            people.erase(people.begin());
        }
        
        answer++;
    }
    
    return answer;
}
