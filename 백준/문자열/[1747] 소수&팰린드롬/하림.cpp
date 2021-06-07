//
//  main.cpp
//  [1747] 소수&팰린드롬
//
//  Created by 정하림 on 2021/06/07.
//
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1003001

int sieve[1003002];

int N, idx;

bool check_p(int n){
    string s = to_string(n);
    
    int len = (int)s.length();
    
    if(len==1){
        return true;
    }
    
    for(int i=0; i<len/2; i++){
        if(s[i]!=s[len-1-i]){
            return false;
        }
    }
    
    return true;
}

void input() {
    cin >> N;
}

void solution() {
    for(int i=2; i<=MAX; i++){
        sieve[i] = i;
    }
    
    for(int i=2; i<=MAX; i++){
        if(sieve[i]==0){
            continue;
        }
        for(int j=i+i; j<=MAX; j+=i){
            sieve[j]=0;
        }
    }
    
    for(int i=N; i<=MAX; i++){
        if(sieve[i]!=0){
            if(check_p(sieve[i])){
                cout << sieve[i];
                break;
            }
        }
    }
}

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    
    solution();
    
    return 0;
}
