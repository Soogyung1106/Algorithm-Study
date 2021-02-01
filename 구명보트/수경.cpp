#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    //오름차순 정렬
    sort(people.begin(), people.end()); 
    
    int answer = 0;
    int L = 0, R = people.size()-1;
    
    while(L<=R){
      if(people[L]+people[R] <= limit) L++;
      answer++; //가장 작은것과 태워도 못 태우면 가장 무거운 것은 혼자 태우기.
      R--;
    }
    
    return answer;
}
