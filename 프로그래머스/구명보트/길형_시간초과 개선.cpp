#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left = 0, right = people.size() - 1;

    sort(people.begin(), people.end(), greater<int>());
    
    while(left <= right)
    {
        if(people[left] + people[right] <= limit)
        {
            right--;
        }
        
        left++;
        answer++;
    }
    
    return answer;
}
