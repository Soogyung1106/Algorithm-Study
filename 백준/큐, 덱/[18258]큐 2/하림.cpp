//
//  main.cpp
//  [18258] 큐2
//
//  Created by 정하림 on 2021/05/14.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

void solution();
void push();
int pop();
int size();
int empty();
int front();
int back();

queue<int> q;

int main(int argc, const char * argv[]) {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    solution();
    
    return 0;
}

void solution() {
    int N;
    string command;
    char first_cmd;
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> command;
        first_cmd = command[0];
        
        switch (first_cmd) {
            case 'p':
                if(command[1]=='u'){
                    push();
                }
                else{
                    cout << pop() << "\n";
                }
                break;
            case 's':
                cout << size() << "\n";
                break;
                
            case 'e':
                cout << empty() << "\n";
                break;
                
            case 'f':
                cout << front() << "\n";
                break;
                
            case 'b':
                cout << back() << "\n";
                break;
                
            default:
                break;
        }
    }
}

void push(){
    int X;
    cin >> X;
    q.push(X);
}

int pop(){
    int result = -1;
    if(!q.empty()){
        result  = q.front();
        q.pop();
    }
    return result;
}

int size(){
    return (int)q.size();
}

int empty(){
    if(q.empty()){
        return 1;
    }
    else{
        return 0;
    }
}

int front(){
    int result = -1;
    if(!q.empty()){
        result = q.front();
    }
    return result;
}

int back(){
    int result = -1;
    if(!q.empty()){
        result = q.back();
    }
    return result;
}
