//
//  main.cpp
//  [15927] 회문은 회문이아니야!
//
//  Created by 정하림 on 2021/06/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;

int answer = -1;

bool is_pel(){
    for(int i=0, j=(int)s.length()-1; i<j; i++,j--){
        if(s[i]!=s[j]){
            return false;
        }
    }
    return true;
}

bool is_one_letter(){
    for(int i=1; i<s.length(); i++){
        if(s[0]!=s[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    
    if(is_pel()){
        if(is_one_letter()){
            answer = -1;
        }
        else{
            answer = s.length()-1;
        }
    }
    else{
            answer = s.length();
    }
    
    cout << answer;
    
    return 0;
}
