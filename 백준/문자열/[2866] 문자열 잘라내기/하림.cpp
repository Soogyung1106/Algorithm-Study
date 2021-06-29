//
//  main.cpp
//  [2866] 문자열 잘라내기
//
//  Created by 정하림 on 2021/06/29.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

int r, c;

char table[1000][1000];

void input(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> table[i][j];
        }
    }
}

void solution(){
    set<string> col;
    for(int i=0; i<c; i++){
        string temp = "";
        
        for(int j=0; j<r; j++){
            temp += table[j][i];
        }
        
        col.insert(temp);
    }
    
    int count = 0;
    
    for(int i=0; i<r-1; i++){
        set<string> next_col;
        for(auto s : col){
            next_col.insert(s.substr(1));
        }
        if(col.size() != next_col.size()){
            break;
        }
        
        count++;
        col = next_col;
    }
    
    cout << count;
}

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    solution();
    
    return 0;
}
