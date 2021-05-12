#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    int column = board.size();
    int row = board[0].size();
    
    for(int y = 1; y < column; y++){
        for(int x = 1; x < row; x++){
            if(board[y][x]==0){
                continue;
            }
            board[y][x]=min(min(board[y-1][x-1],board[y-1][x]),board[y][x-1]) + 1;
        }
    }
    
    for(int y = 0; y < column; y++){
        for(int x = 0; x < row; x++){
            answer = max(answer, board[y][x]);
        }
    }
    
    return answer*answer;
}
