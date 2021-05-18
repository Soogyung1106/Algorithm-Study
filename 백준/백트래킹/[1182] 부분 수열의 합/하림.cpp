//
//  main.cpp
//  [16657] 부분수열의 합
//
//  Created by 정하림 on 2021/05/18.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N, S, answer;
int arr[20];

void dfs(int start, int end, int sum){
    if(start==end){
        return;
    }
    if(sum+arr[start] == S){
        answer++;
    }
    
    dfs(start+1, end, sum);
    dfs(start+1, end, sum + arr[start]);
}

void input(){
    cin >> N >> S;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
}

int main(int argc, const char * argv[]) {
    
    input();
    
    dfs(0, N, 0);
    
    cout << answer;
    
    return 0;
}
