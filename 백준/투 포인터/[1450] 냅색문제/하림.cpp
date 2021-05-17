//
//  main.cpp
//  [1450] 냅색문제
//
//  Created by 정하림 on 2021/05/16.
//

#include <iostream>
#include<algorithm>
using namespace std;

#define MAX 1<<15

int way1[MAX], way2[MAX], len1, len2, object[15];

int N, C, answer;


void dfs(int start, int end, int sum, int C , bool flag){
    if(sum > C) {
        return;
    }
    
    if(start==end){
        if(flag) {
            way1[len1++] = sum;
        }
        else {
            way2[len2++] = sum;
        }
        return;
    }
    dfs(start+1, end, sum, C, flag);
    dfs(start+1, end, sum+object[start], C, flag);
}


int main(int argc, const char * argv[]) {
    
    cin >> N >> C;
    
    for(int i=0; i<N/2; i++) {
        cin >> object[i];
    }
    
    dfs(0, N/2, 0, C, true);
    
    sort(way1, way1+len1);

    for(int i=N/2; i<N; i++) {
        cin >> object[i-N/2];
    }
    
    dfs(0, N-N/2, 0, C, false);
    
    sort(way2, way2+len2);

    for(int i=0, j=len2-1; i<len1&&j>=0; i++){
        while( way1[i]+way2[j] > C ) {
            j--;
        }
        
        answer += j+1;
    }
    
    cout << answer;
    return 0;
}

