//
//  main.cpp
//  [1644] 소수의 연속합
//
//  Created by 정하림 on 2021/05/13.
//

#include <iostream>   
#include <vector>

using namespace std;

int N, answer;

int sieve[4000001];

vector<int> prime_number;

void input() {
    cin >> N;
}

void make_prime_number() {
    for(int i = 2; i <= N; i++){
        sieve[i] = i;
    }
    
    for(int i = 2; i <= N; i++){
        if(sieve[i] == 0){
            continue;
        }
        for(int j = i + i; j <= N; j = i+j) {
            sieve[j] = 0;
        }
    }
    
    for(int i = 2; i <= N; i++){
        if(sieve[i] != 0){
            prime_number.push_back(sieve[i]);
        }
    }
}

void solution() {
    int head = 0, tail = 0;
    int size = prime_number.size();
    int sum = 0;
    while(true){
        // tail이 마지막 인덱스에 가있는 경우에도 head가 이동할 수 있어야 함
        if(sum >= N){
            sum = sum - prime_number[head];
            head++;
        }
        else if (tail == size) {
            break;
        }
        else{
            sum = sum + prime_number[tail];
            tail++;
        }
        
        if(sum == N){
            answer++;
        }
    }
    
    cout << answer << endl;
}

int main(int argc, const char * argv[]) {
    
    input();
    
    make_prime_number();
    
    solution();
    
    return 0;
}
