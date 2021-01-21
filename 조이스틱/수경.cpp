#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int len = name.size();
    int mid = len/2;
    
    int F = 0; int B = 0; int HF = 0; int HB=0;
    int answer = 0;
    for(int i=0;i<len;i++){
    
        //알파벳 이동 개수 더하기 
        if(name[i] <= 'N') answer += name[i] -'A'; 
        else answer += 'Z' - name[i] +1;
        
        //커서 이동의 경우 4가지 (→,←,→ ←,← →) 
        if(i==0) continue;
        
        if(name[i] != 'A'){
            F = i;
            if(i<=mid) HF = i;
        }
        if(name[len-i] != 'A'){
            B = i;
            if(len-i>mid) HB = i;
        }
    }
    cout<<F<<", "<<B<<", "<<HF<<", "<<HB;
    //커서 이동 개수 더하기
    return answer + min(min(F, B), min(HB * 2 + HF, HF * 2 + HB)); 

}
