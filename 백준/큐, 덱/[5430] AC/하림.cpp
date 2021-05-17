//
//  main.cpp
//  [5430] AC
//
//  Created by 정하림 on 2021/05/17.
// 1950

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int T;

void output(string p, int n, deque<int> &dq){
    bool forward_direction = true;
    int plen = p.length();
    for(int i=0; i<plen; i++){
        if(p[i]=='R'){
            forward_direction = !forward_direction;
        }
        else if(p[i]=='D'){
            if(n==0){
                cout << "error" << "\n";
                return;
            }
            n--;
            if(forward_direction){
                dq.pop_front();
            }
            else{
                dq.pop_back();
            }
        }
        else{
            cout << "error" << "\n";
            return;
        }
    }
    
    if(n==0){
        cout << "[]" << "\n";
        return;
    }

    cout << "[";
    if(forward_direction){
        for(int i=0; i<n; i++){
            cout << dq[i];
            if(i!=n-1){
                cout << ",";
            }
        }
    }
    else{
        for(int i=n-1; i>=0; i--){
            cout << dq[i];
            if(i!=0){
                cout << ",";
            }
        }
    }
    cout << "]" << "\n";
}

void input() {
    
    string p, x, temp;
    int n;
    deque<int> dq;
    
    cin >> p >> n >> x;
    
    int xlen = x.length();
    for(int i=1; i<xlen; i++){
        if( (x[i]==',') || (x[i]==']') ){
            if(temp.length()!=0){
                dq.push_back(stoi(temp));
                temp = "";
            }
        }
        else{
            temp = temp + x[i];
        }
    }
    
    output(p, n, dq);
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for(int i=0; i<T; i++){
        input();
    }
        
    return 0;
}
