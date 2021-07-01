//
//  main.cpp
//  [20166] 문자열 지옥에 빠진 호석
//
//  Created by 정하림 on 2021/07/01.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N, M, K;
char table[10][10];
vector<string> god;

int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

map<string, int> answer;

void input(){
    cin >> N >> M >> K;
    
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            cin >> table[n][m];
        }
    }
    
    string temp = "";
    for(int k=0; k<K; k++){
        cin >> temp;
        god.push_back(temp);
    }
}

void dfs(string result, int y, int x){
    
    result = result + table[y][x];
    
    answer[result]++;
    
    if(result.length() == 5){
        return;
    }
    
    int next_y, next_x;

    for(int i=0; i<8; i++){
        next_y = y+dy[i];
        next_x = x+dx[i];
        
        if(next_y < 0){
            next_y = N-1;
        }
        else if(next_y >= N){
            next_y = 0;
        }
        if(next_x < 0){
            next_x = M-1;
        }
        else if(next_x >= M){
            next_x = 0;
        }

        dfs(result, next_y, next_x);
    }
}

void solution(){
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            dfs("", n, m);
        }
    }
    
    for(int k=0; k<K; k++){
        cout << answer[god[k]] << "\n";
    }
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    solution();
    
    return 0;
}

