#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int,int>> wait; // first -> index, second -> 우선순위
    vector<int> pr;
    pair<int,int> temp;
    int count = 0;
    
    for(int i = 0 ; i < priorities.size() ; i++)
    {
        wait.push_back(pair<int,int>(i, priorities[i]));
        pr.push_back(priorities[i]);
    }
    
    while(!wait.empty())
    {
        sort(pr.begin(), pr.end(), greater<int>());
        temp = wait.front();
        wait.erase(wait.begin());
        count++;
        
        if(pr.front() == temp.second)
        {
            pr.erase(pr.begin());
            if(temp.first == location)
            {
                return count;
            }
        }
        else
        {
            wait.push_back(temp);
            count--;
        }
    }
}
