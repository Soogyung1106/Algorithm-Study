//
//  main.cpp
//  [4358] 생태학
//
//  Created by 정하림 on 2021/06/09.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, float> m;
vector<string> keys;
int cnt;


void input(){
    string temp;
    
    while(getline(cin, temp)) {
        if(m[temp]==0){
            keys.push_back(temp);
        }
        m[temp]++;
        cnt++;
    }
}

void solution(){
    sort(keys.begin(), keys.end());
    cout << fixed;
    cout.precision(4);
    
    for(auto key : keys){
        cout << key << " " << (m[key]/cnt)*100 << "\n";
    }
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    
    solution();
    
    return 0;
}
