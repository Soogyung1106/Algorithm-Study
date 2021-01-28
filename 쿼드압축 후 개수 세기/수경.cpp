#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer{0, 0};
vector<vector<int>> quard;

bool check(int row, int col, int len){
    int cmp = quard[row][col]; 
    
    for(int i=row;i<row+len;i++){
        for(int j=col;j<col+len;j++) 
            if(cmp != quard[i][j]) return false;   
    }
    
    return true;
}

void recursion(int row, int col, int len){
   
    //all 같은 원소인지 check
    //if 같은 원소라면 하나의 수로 바꿔주고 answer 값 증감시키기
    if(check(row, col, len)){   
        answer[quard[row][col]]++; 
        return;
    }
    //else 다르다면 4개로 분해 
    else{
        recursion(row, col, len/2);
        recursion(row, col+len/2, len/2);
        recursion(row+len/2, col, len/2);
        recursion(row+len/2, col+len/2, len/2);
    }
}

vector<int> solution(vector<vector<int>> arr) {

    quard = arr;    
    recursion(0, 0, arr.size()); //행, 열, 정사각형의 길이
    return answer;
}
