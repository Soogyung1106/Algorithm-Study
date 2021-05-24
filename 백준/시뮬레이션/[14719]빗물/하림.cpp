//
//  main.cpp
//  [14719] 빗물
//
//  Created by 정하림 on 2021/05/24.
//

#include <iostream>
#include <vector>

using namespace std;

int H, W;
int world[500];


void input(){
    cin >> H >> W;
    for(int i=0; i<W; i++){
        cin >> world[i];
    }
}

void solution(){
    int answer = 0;
    for(int i=1; i<=H; i++){
        
        int last = -1;
        
        for(int j=0; j<W; j++){
            if(world[j] < i) {
                continue;
            }
            
            if(last==-1){
                last = j;
            }
            else{
                answer += j - last - 1;
                last = j;
            }
        }
    }
    
    cout << answer;
    
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    
    solution();
    
    return 0;
}
