//
//  main.cpp
//  [3709] 레이저빔은 어디로
//
//  Created by 정하림 on 2021/05/28.
//

#include <iostream>

using namespace std;

int testcase, n, r;
int x, y;
int map[52][52];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void solution(){
    
    // 상 우 하 좌
    //  0 1 2 3
    int dir = 0;
    
    if(x==0 || x==n+1){
        if(x==0){
            dir = 2;
        }
        else{
            dir = 0;
        }
    }
    else if(y==0 || y==n+1){
        if(y==0){
            dir = 1;
        }
        else{
            dir = 3;
        }
    }
    
    while(true){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        
        if(nx <= 0 || nx >= n+1 || ny <= 0 || ny >= n+1){
            cout << nx << " " << ny << "\n";
            break;
        }
        
        if(map[nx][ny]){
            dir = (dir+1)%4;
        }
        
        x = nx;
        y = ny;
    }
}

void input(){
    cin >> testcase;
    
    for(int i=0; i<testcase; i++){
        cin >> n >> r;
        
        for(int j=0; j<n+2; j++){
            for(int k=0; k<n+2; k++){
                map[j][k] = 0;
            }
        }
        
        for(int j=0; j<r; j++){
            cin >> x >> y;
            map[x][y] = 1;
        }
        cin >> x >> y;
        solution();
    }
}

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
        
    return 0;
}
