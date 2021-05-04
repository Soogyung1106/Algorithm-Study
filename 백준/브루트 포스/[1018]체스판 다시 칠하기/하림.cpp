//
//  main.cpp
//  [1018]체스판 다시 칠하기
//
//  Created by 정하림 on 2021/05/03.



/*
// 첫번째 풀이방식(flag를 통한 비교)
 
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int M, N;
int board[50][50] = {-1};
int answer = 9999;

void input() {
    
    cin >> N >> M;
    
    char temp;
    
    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            cin >> temp;
            if(temp=='B'){
                board[y][x]=0;
            }
            else if(temp=='W'){
                board[y][x]=1;
            }
        }
    }
    
}

void calc(int add_y, int add_x){
    int first_black = 0, first_white = 0, flag = 0;

    for(int y=0; y<8; y++) {
        for(int x=0; x<8; x++) {
            if(board[y+add_y][x+add_x] == flag){
                first_white++;
            }
            if(board[y+add_y][x+add_x] == !flag){
                first_black++;
            }
            
            if(flag==0){
                flag = 1;
            }
            else{
                flag = 0;
            }
        }
        if(flag==0){
            flag = 1;
        }
        else{
            flag = 0;
        }
    }
    
    answer = min(answer,min(first_black, first_white));
}

int main(void) {
    
    input();
    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            calc(i,j);
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
*/




#include <iostream>
#include <string>
#include <iostream>

using namespace std;

int M, N;
char board[50][50] = {0};
int answer = 9999;
char black_board[9][9] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};
char white_board[9][9] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};


void input() {
   
   cin >> N >> M;
      
   for(int y=0; y<N; y++) {
       for(int x=0; x<M; x++) {
           cin >> board[y][x];
       }
   }
   
}

void calc(int add_y, int add_x){
    int black_cnt = 0, white_cnt = 0;

    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){
            if(board[y+add_y][x+add_x] != black_board[y][x]){
                black_cnt++;
            }
            if(board[y+add_y][x+add_x] != white_board[y][x]){
                white_cnt++;
            }
        }
    }
    
    answer = min(answer,min(black_cnt, white_cnt));
}

int main(void) {
    
    input();
    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            calc(i,j);
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
