//
//  main.cpp
//  [3107] IPv6
//
//  Created by 정하림 on 2021/06/29.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//string group[8];
vector<string> group;
int skip_place = -1;

void input() {
    string ip;
    cin >> ip;
    
    if(ip.find("::") != string::npos){
        ip = ip.replace(ip.find("::"),2,"*");
    }
        
    string temp = "";

    for(int i=0; i<ip.length(); i++){
        if(ip[i]=='*'){
            if(temp!=""){
                group.push_back(temp);
                temp = "";
            }
            skip_place = group.size();
        }
        else if(ip[i]==':'){
            group.push_back(temp);
            temp = "";
        }
        else{
            temp += ip[i];
        }
    }
    group.push_back(temp);
}

void solution() {
    
    for(auto& g : group){
        int cnt = 4 - g.length();
        for(int i=0; i < cnt; i++){
            g = "0" + g;
        }
    }
    
    string answer = "";
    for(int i=0; i<group.size(); i++){
        if(i==skip_place){
            for(int j=0; j<8-group.size(); j++){
                answer += "0000:";
            }
        }
        answer += group[i] + ":";
    }
    
    answer.pop_back();
    cout << answer << "\n";
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    solution();
    
    return 0;
}
