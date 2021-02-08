#include <string>
#include <iostream>

using namespace std;

int solution(string s) {
    
    int min = s.size(); //압축하지 않았을 떄 길이
    for(int i=1;i<=s.size()/2;i++){ //자르는 단위
        
        int count = 1; string change;
        string cmp = s.substr(0, i); int j=0;
        for(j= i;j<s.size();j+=i){
            if(s.substr(j, i) == cmp)  count++;
            else{
                if(count >=2)  change += to_string(count); 
                change += cmp;
                count = 1;
                cmp = s.substr(j, i);
            } 
                  
            if(!(j+i<s.size())){ //for문 끝나기 전 단어 저장
                if(count >=2)  change += to_string(count); 
                change += cmp; 
            }
        }
        
        if(j < s.size()-1) change += s.substr(j, s.size()-j-1); //남은 문자열 붙이기
        
        min = (min>change.size()) ? change.size() : min; //문자열 길이 저장

    }
    
    return min;
    
}
