
//  main.cpp
//  [1342] 행운의 문자열
//
//  Created by 정하림 on 2021/06/14.
//

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

string S;

int length;

bool visited[10];

vector<string> result;

string temp = "";


void input(){
    cin >> S;
}


void dfs(int index){
    if(index==length){
        result.push_back(temp);
        return;
    }
    for(int i=0; i<length; i++){
        if(visited[i]){
            continue;
        }
        if(temp.back()==S[i]){
            continue;
        }
        temp = temp + S[i];
        visited[i] = true;
        dfs(index + 1);
        temp.pop_back();
        visited[i] = false;
    }
}

void solution(){
    length = (int)S.size();
    dfs(0);
    
    sort(result.begin(), result.end());
    
    result.erase(unique(result.begin(),result.end()), result.end());
    
    cout << result.size();
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    
    solution();
    
    return 0;
}
