#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int Size; //move 판의 사이즈

bool canOpen(vector<vector<int>> move, vector<vector<int>> lock){
    //하나라도 0인 경우 return false, all 1인 경우 return true
    for(int i=lock.size();i<2*lock.size();i++){
        for(int j=lock.size();j<2*lock.size();j++){
            //돌기와 돌기가 만나면 안 됨.
            if(move[i][j] && lock[i-lock.size()][j-lock.size()]) return false;
            if(!(move[i][j] | lock[i-lock.size()][j-lock.size()])) return false; 
        }  
    }
    return true;
}

vector<vector<int>> fillKey(int y, int x, vector<vector<int>> move, vector<vector<int>> key){
    //y,x 부터 채우기..
    for(int i = y;i<y+key.size();i++)
        for(int j = x;j<x+key.size();j++)
            move[i][j] = key[i-y][j-x];

    return move;
}              
           
vector<vector<int>> turn90(vector<vector<int>> key){
    
    vector<vector<int>> tmp(key.size(), vector<int>(key.size(), 0));
    int col = key.size()-1;
    
    for(int i=0;i<key.size();i++){ //행
        queue<int> q; 
        for(int j=0;j<key.size();j++) //열
            q.push(key[i][j]);   
        
        for(int k=0;k<key.size();k++){ //회전
            tmp[k][col] = q.front();
            q.pop();
        }
        col--;
    }
    
    return tmp;
}
               
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    Size = lock.size()*3;
    for(int i=0;i<4;i++){ 
        //1. key를 90도 방향으로 회전 4번
        key = turn90(key);
        
        //2. key를 한 칸씩 이동. (3N X 3N) -> T/F 판단.
        for(int j = 0;j < Size;j++){
            for(int k = 0;k < Size;k++){
                if(j+key.size() > Size || k+key.size() > Size) continue; //범위 체크
                
                //move[j][k]를 기점으로 key 움직이기 
                vector<vector<int>> move(Size, vector<int>(Size, 0));
                move = fillKey(j, k, move, key);
                
                //가운데 부분 lock과 |연산 
                if(canOpen(move, lock)) return true;    
            }    
        }
    }
    
    return false;
}
