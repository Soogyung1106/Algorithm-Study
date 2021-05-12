#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    int out = routes[0][1];
    
    for(int i=1;i<routes.size();i++)
    {
        if(routes[i][0] <= out) // 겹치지 않는 경우 
        {
            out = min(routes[i][1], out);
        }
        else // 겹치는 경우, 카메라를 한 대 더 설치해야함
        {
            answer++;
            out = routes[i][1];
        }
    }
    return answer;
}
