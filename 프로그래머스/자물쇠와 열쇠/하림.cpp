#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N,M;

bool calc(vector<vector<int>> key, vector<vector<int>> lock, vector<vector<int>> board, int y, int x) {
    
    int N = lock.size();
    int M = key.size();   
    
    for(int i=0; i<M; i++) {
       for(int j=0; j<M; j++){
            board[i+y][j+x]=board[i+y][j+x]+key[i][j];
       } 
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i+M-1][j+M-1]!=1){
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> rotate_key(int M, vector<vector<int>> key) {
    vector<vector<int>> temp(M,vector<int>(M,0));
    
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            temp[i][j] = key[M-1-j][i];
        }
    }
    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int N = lock.size();
    int M = key.size();
    int cnt = 0;
    
    int size = (2*M)-2+N;
    
    vector<vector<int>> board(size,vector<int>(size,0));
    
    // 가운데를 lock부분으로 초기화
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i+M-1][j+M-1]=lock[i][j];
        }
    }
    
    while(cnt<4){
        for(int y=0; y<N+M-1; y++){
            for(int x=0; x<N+M-1; x++){
                if(calc(key,lock,board,y,x)) {
                    answer = true;
                    return answer;
                }
            }
        }
        key = rotate_key(M, key);
        cnt++;
    }
    
    return answer;
    
}
