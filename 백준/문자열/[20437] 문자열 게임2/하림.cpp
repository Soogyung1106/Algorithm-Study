//
//  main.cpp
//  [20437] 문자열 게임 2
//
//  Created by 정하림 on 2021/07/02.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string W;
int K, T;
int min_len = 10001, max_len = 0;

void find_length(char alpa){
    vector<int> index;
    for(int i=0; i<W.length(); i++){
        if(W[i] == alpa){
            index.push_back(i);
        }
    }
    
    // 0 2 3 4 6
    int length = 0;
    for(int i=0; i<index.size() - K + 1; i++){
        length = index[i+K-1] - index[i] + 1;
        min_len = min(length, min_len);
        max_len = max(length, max_len);
    }
}

void solution(){
    map<char, int> cnt;
    
    for(int i=0; i<W.length(); i++){
        cnt[W[i]]++;
    }
    
    bool is_exist = false;
    for(auto c : cnt){
        if(c.second >= K){
            is_exist = true;
            find_length(c.first);
        }
    }
    
    if(is_exist){
        cout << min_len << " " << max_len << "\n";
    }
    else{
        cout << -1 << "\n";
    }
}
    

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for(int t=0; t<T; t++){
        min_len = 10001;
        max_len = 0;
        cin >> W >> K;
        solution();
    }
    
    return 0;
}
