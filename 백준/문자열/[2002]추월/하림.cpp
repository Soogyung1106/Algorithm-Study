//
//  main.cpp
//  [2002] 추월
//
//  Created by 정하림 on 2021/06/16.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N;
map<string, int> in;
vector<string> out;
bool illegal[1000];

void input(){
    cin >> N;
    
    string temp;
    
    for(int i=0; i<N; i++){
        cin >> temp;
        in.insert({temp, i});
    }
    
    for(int i=0; i<N; i++){
        cin >> temp;
        out.push_back(temp);
    }
}

void solution(){
    
    int answer = 0;
    
    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(in[out[i]] < in[out[j]]){
                if(!illegal[in[out[j]]]){
                    illegal[in[out[j]]] = true;
                    answer++;
                }
            }
        }
    }
    
    cout << answer;
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    
    solution();
    
    return 0;
}
