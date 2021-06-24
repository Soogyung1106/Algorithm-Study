//
//  main.cpp
//  [1990] 소수인팰린드롬
//
//  Created by 정하림 on 2021/06/24.
//

#include <iostream>
#include <string>

#define MAX 100000001

using namespace std;
bool prime[100000001];

int a, b;

void ceive(int end){
    for(int i=2; i<=end; i++){
        prime[i] = true;
    }
    
    for(int i=2; i<=end; i++){
        if(!prime[i]){
            continue;
        }
        for(int j=i+i; j<=end; j+=i){
            prime[j] = false;
        }
    }
}

bool is_pel(string temp){
    for(int i=0, j=temp.length()-1; i<=j; i++,j--){
        if(temp[i] != temp[j]){
            return false;
        }
    }
    return true;
}

void solution(int start, int end){
    if(b>10000000){
        b = 10000000;
    }
    ceive(b);
    
    for(int i=start; i<=end; i++){
        if(prime[i] && is_pel(to_string(i))){
            cout << i << "\n";
        }
    }
}

int main(int argc, const char * argv[]) {

    cin >> a >> b;
    
    solution(a,b);
    
    cout << -1;
    
    return 0;
}
