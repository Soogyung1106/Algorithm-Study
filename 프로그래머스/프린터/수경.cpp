#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;


int getMaxIdx(vector<pair <int, int>>& vp){
    int max = 0; int idx = 0;
    for(int i=0;i<vp.size();i++){
        if(vp[i].first > max){
            max = vp[i].first;
            idx = vp[i].second;
        } 
    }
    
    return idx;
}


int solution(vector<int> priorities, int location) {
    
    //(중요도, 인덱스) 페어로 벡터 만들어주기 
    vector<pair <int, int>> vp; 
    for(int i = 0;i<priorities.size();i++)
        vp.push_back(make_pair(priorities[i], i));
    

    //push, pop하면서 중요도에따라 출력하기, conut값 증가-> 출력시 인덱스가 location인지 보기 -> 똑같다면 count 출력
    int count = 0;
    while(!vp.empty()){
        auto front = vp.front();
        if(front.second == getMaxIdx(vp)){
            count++;
            if(front.second == location) return count;    
        }else  vp.push_back(front);
        
        vp.erase(vp.begin()); 
    }
    
}
