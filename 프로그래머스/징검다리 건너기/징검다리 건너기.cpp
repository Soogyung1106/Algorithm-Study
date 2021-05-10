#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool can_go(vector<int> stones, int x, int k){
    //x명까지 다리를 건널 수 있는지 여부(T/F)를 반환.  
    //zero_cnt가 연속되게 k개 이상 있다면 다리를 건널 수 없음. 
    int zero_cnt = 0, max_cnt = 0; 
    for(int i=0;i<stones.size();i++){
        if(stones[i] < x) zero_cnt++;
        else{
            if(zero_cnt > 0){
                max_cnt = max(max_cnt, zero_cnt);
                zero_cnt = 0;
            }
        }
    }
    max_cnt = max(max_cnt, zero_cnt);
    return max_cnt >= k ? false : true;
}

int solution(vector<int> stones, int k) {
    
    int start = 1, end = *max_element(stones.begin(), stones.end());
    int mid = 0; //다리를 건널 수 있는 사람. 
    int answer = 0;
    while(start <= end){
       mid = (start + end)/2;
       if(can_go(stones, mid, k)){ //다리를 건널 수 있는지 확인.
           answer = max(answer, mid);
           start = mid + 1;
       }else end = mid - 1;
    }
    
    return answer;
}