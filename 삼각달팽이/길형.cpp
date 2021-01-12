#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    // 좌표계 이용 N x N 행렬이라 생각!
    int x = 0;
    int y = -1;
    vector<vector<int>> board(n, vector<int>(n, 0)); // N x N 사이즈 좌표 생성
    int direction = 0; // 0,1,2 순서로 0 -> y-1, 1-> x+1, 2-> x-1,y-1
    int a = 0 , b = 0; // a -> x를 어디로 이동, b -> y를 어디로 이동
    int cnt = 1;
    int repeat = n; // 반복 회수 n, n-1, n-2...
    
    while(cnt <= (n*(n+1)) / 2)
    {
        if(direction % 3 == 0)
        {
            a = 0;
            b = 1;
        }
        else if(direction % 3 == 1)
        {
            a = 1;
            b = 0;
        }
        else
        {
            a = -1;
            b = -1;
        }

        for(int i = repeat ; i > 0 ; i--) 
        { 
            
            x += a;
            y += b;
            board[y][x] = cnt;
            cnt++;
        }
        repeat--;
        direction++;
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(board[i][j] != 0) answer.push_back(board[i][j]);
        }
    }

    
    return answer;
}
