#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> board)
{
    
    if(board.size() == 1|| board[0].size() == 1){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]) return 1;
            }
        }
    }
        
    
    int answer = 0;
    for(int i=1;i<board.size();i++){ //행
        for(int j=1;j<board[0].size();j++){ //열
            if(board[i][j] && board[i-1][j] && board[i][j-1] && board[i-1][j-1]){
                board[i][j] = min(min(board[i-1][j], board[i-1][j-1]), board[i][j-1]) + 1;
                //if(answer<board[i][j]) answer = board[i][j];
            }     
            if(answer<board[i][j]) answer = board[i][j];
        }
    }

    return pow(answer,2);
}
