//
//  main.cpp
//  [2470] 두 용액
//
//  Created by 정하림 on 2021/05/12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> status;

void input() {
    cin >> N;
    
    int temp;
    
    for(int i=0; i<N; i++){
        cin >> temp;
        status.push_back(temp);
    }
}

void solution() {
    int head = 0, tail = N-1;
    int min = 2000000000;
    int answer[2];
    
    while(head < tail){
        int sum = status[head]+ status[tail];
        int abs_sum;
        
        if(sum < 0) {
            abs_sum = sum * -1;
        }
        else{
            abs_sum = sum;
        }
        
        if(abs_sum <= min){
            min = abs_sum;
            answer[0] = status[head];
            answer[1] = status[tail];
        }
        
        if(sum < 0) {
            head++;
        }
        if(sum == 0){
            break;
        }
        if(sum > 0){
            tail--;
        }
    }
    
    cout << answer[0] << " " << answer[1];
}

int main(int argc, const char * argv[]) {

    input();
    
    sort(status.begin(), status.end());
    
    solution();
    
    return 0;
}
