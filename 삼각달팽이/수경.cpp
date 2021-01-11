#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;


pair<int, int> pos = {-1, 0}; //시작 위치
int num = 0;
int N = 0;

void down(vector<vector <int>>& v){
    int row = ++pos.first; //행
    int col = pos.second; //열
    
    int i;
    for(i = row;i<N;i++){
        if(v[i][col] != 0)  break;   
        
        v[i][col] = ++num;
        pos.first = i;
    }

}

void right(vector<vector <int>>& v){
    int row = pos.first; //행
    int col = ++pos.second; //열
    
    for(int i = col;i<N;i++){
        if(v[row][i] != 0)  break;   
        
        v[row][i] = ++num;
        pos.second = i;
    }
    

}

void up(vector<vector <int>>& v){
    
    int row = --pos.first; //행 3
    int col = --pos.second; //열 2
    
    for(int i = row, j= col;i>0, j > 0;i--, j--){
        if(v[i][j] != 0)  break;   
    
        v[i][j] = ++num;
        pos.first = i;
        pos.second = j;      
    }
    
}


vector<int> solution(int n) {
    
    N = n;
    vector<vector <int>> v(n, vector<int> (n, 0)); //nxn을 0으로 초기화
    
    //순회하면서 넣기
    int count = 0; 
    for(int i=1;i<=n;i++){
        count++;
        if(count>3) count -= 3;
    
        if(count == 1)  down(v); 
        if(count == 2)  right(v);
        if(count == 3)  up(v);  
    }

    //answer에 넣기
    vector<int> answer;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            if(v[i][j] != 0) answer.push_back(v[i][j]);
            else break;
        }
    }
    
    return answer;
}
