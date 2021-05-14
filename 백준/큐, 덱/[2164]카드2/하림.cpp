//
//  main.cpp
//  [2164] 카드2
//
//  Created by 정하림 on 2021/05/14.
//

#include <iostream>
#include <queue>

using namespace std;

int N;

void init(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
}

void input(){
    cin >> N;
}

void solution(){
    queue<int> q;
    
    for(int i=1; i<=N; i++){
        q.push(i);
    }
    
    while(q.size()!=1){
        int top;
        q.pop();
        
        top = q.front();
        q.pop();
        q.push(top);
    }
    
    cout << q.front();
}

int main(int argc, const char * argv[]) {

    init();
    
    input();
    
    solution();
    
    return 0;
}
