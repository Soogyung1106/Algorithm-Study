//
//  main.cpp
//  [2671] 잠수함식별
//
//

#include <iostream>
#include <string>
#include <regex>

using namespace std;

string sound;

void input(){
    cin >> sound;
}

void solution(){
    regex pattern("(100+1+|01)+");
    if(regex_match(sound, pattern)){
        cout << "SUBMARINE";
    }
    else{
        cout << "NOISE";
    }
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    
    solution();
    
    return 0;
}
