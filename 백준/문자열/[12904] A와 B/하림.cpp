//
//  main.cpp
//  [12904] A와 B
//
//  Created by 정하림 on 2021/06/10.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
bool is_possible;

void input(){
    cin >> S >> T;
}

void solution(){

    while(T.length() != S.length()){
        if(T[T.length()-1] == 'A'){
            T.pop_back();
        }
        else{ // B
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    if(!T.compare(S)){
        cout << 1;
    }
    else{
        cout << 0;
    }
}

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    solution();

    return 0;
}
