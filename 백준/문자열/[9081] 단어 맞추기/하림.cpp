//
//  main.cpp
//  [9081] 단어 맞추기
//
//  Created by 정하림 on 2021/06/25.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T=0;
    
    cin >> T;
    
    
    for(int t=0; t<T; t++){
        string word, temp;
        cin >> word;
        temp = word;
        if(!next_permutation(temp.begin(), temp.end())){
            cout << word << "\n";
        }
        else{
            cout << temp << "\n";
        }
    }
    
    return 0;
}
