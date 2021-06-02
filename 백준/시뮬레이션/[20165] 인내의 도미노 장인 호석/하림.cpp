//
//  main.cpp
//  [20165] 인내의 도미노 장인 호석
//
//  Created by 정하림 on 2021/06/02.
//

#include <iostream>
#include <vector>

using namespace std;

int board[101][101];
bool stand[101][101];
int N,M,R;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int score;

void input(){
    cin >> N >> M >> R;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> board[i][j];
            stand[i][j] = true;
        }
    }
}

void solution(){
    int X, Y;
    char D;
    int dir = -1; // 북 동 남 서
    for(int i=0; i<R; i++){
        
        cin >> X >> Y >> D;
        
        switch(D){
            case 'N' :
                dir = 0;
                break;
            case 'E' :
                dir = 1;
                break;
            case 'S' :
                dir = 2;
                break;
            case 'W' :
                dir = 3;
                break;
            default:
                break;
        }
        
        if(stand[X][Y]){
            stand[X][Y] = false;
            score++;
            int chain = board[X][Y]-1;
            
            while(true){
                chain--;
                int nx = X + dx[dir];
                int ny = Y + dy[dir];
                
                if(chain < 0 || nx <= 0 || ny <= 0 || nx > N || ny > M){
                    break;
                }
                
                if(stand[nx][ny]){
                    score++;
                    stand[nx][ny] = false;
                    chain = max(chain, board[nx][ny]-1);
                }
                
                X = nx;
                Y = ny;
            }
        }
        
        cin >> X >> Y;
        if(!stand[X][Y]){
            stand[X][Y] = true;
        }
    }
    
    cout << score << "\n";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(stand[i][j]){
                cout << "S ";
            }
            else{
                cout << "F ";
            }
        }
        cout << "\n";
    }
    
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    solution();
    
    return 0;
}
