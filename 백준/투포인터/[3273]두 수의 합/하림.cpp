//
//  main.cpp
//  [3273] 두 수의 합
//
//  Created by 정하림 on 2021/05/12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
int n, x;


void input() {
    int temp;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        a.push_back(temp);
    }
    cin >> x;
}

void solution() {
    int answer = 0, head = 0, tail=n-1;
    
    while(head < tail){
        int sum = a[head] + a[tail];
        
        if(sum == x){
            head++;
            answer++;
        }
        if(sum >= x){
            tail--;
        }
        if(sum < x){
            head++;
        }
    }
    
    cout << answer;
}

int main(int argc, const char * argv[]) {
    
    input();
    
    sort(a.begin(), a.end());
    
    solution();
    
    return 0;
}
