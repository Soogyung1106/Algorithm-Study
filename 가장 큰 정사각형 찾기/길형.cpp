#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;https://github.com/Soogyung1106/Algorithm-Study

int solution(vector<vector<int>> board)
{
    int answer = 0;
    vector<int> temp;
    
    if(board.size() == 1 || board[0].size() == 1) return 1; 
    
    for(int i = 1 ; i < board.size() ; i++)
    {
        for(int j = 1 ; j < board[0].size() ; j++)
        {
            if(board[i][j] == 1)
            {
                //왼쪽점, 위쪽점, 왼쪽 대각선에 있는 점 비교 수행
                board[i][j] = min({board[i-1][j], board[i][j-1], board[i-1][j-1]}) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }
    return answer * answer;
}
