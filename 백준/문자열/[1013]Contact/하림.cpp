//
//  main.cpp
//  [1013] Contact
//
//  Created by 정하림 on 2021/06/08.
//

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int T;

void solution(){
    string temp;
    cin >> temp;
    
    regex pattern("(100+1+|01)+");
    bool pattern_check = regex_match(temp, pattern);

    if(pattern_check){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

void input(){
    cin >> T;
    for(int i=0; i<T; i++){
        solution();
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    
    return 0;
}
