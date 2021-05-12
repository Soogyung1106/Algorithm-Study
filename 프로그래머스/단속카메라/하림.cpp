#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> routes) {
    
    int answer = 0;
   
    sort(routes.begin(), routes.end());
    
    // 차량이 한대일 때
    if(routes.size()==1){
        answer = 1;
        return answer;
    }
    
    int last_end = routes[0][1];
    int different_count = 1;
    
    for(int i=1; i<routes.size(); i++){
        int new_start = routes[i][0];
        int new_end = routes[i][1];
        
        // 만약 차량이 겹치지 않는다면
        if(last_end < new_start) {
            last_end = new_end;
            different_count++;
        }
        
        if(last_end > new_end){
            last_end = new_end;
        }
    }
    
    answer = different_count;
    
    return answer;
}
