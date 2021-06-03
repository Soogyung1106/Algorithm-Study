//
//  main.cpp
//  [1759] 암호만들기
//
//  Created by 정하림 on 2021/06/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;

vector<char> alpa;
bool visit[15];
vector<char> password;

void dfs(int length, char last_alpa, int cnt1, int cnt2){
    if(length==L){
        if(cnt1 >= 1 && cnt2 >= 2){
            for(int i=0; i<L; i++){
                cout << password[i];
            }
            cout << "\n";
        }
        return;
    }
    
    for(int i=0; i<C; i++){
        if(visit[i] || last_alpa > alpa[i]){
            continue;
        }
        visit[i] = true;
        password.push_back(alpa[i]);
        
        switch(alpa[i]){
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' :
                cnt1++;
                break;
            default:
                cnt2++;
                break;
        }
        
        dfs(length+1, alpa[i], cnt1, cnt2);
        
        switch(alpa[i]){
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' :
                cnt1--;
                break;
            default:
                cnt2--;
                break;
        }
        
        password.pop_back();
        visit[i] = false;
    }
}

void input(){
    cin >> L >> C;
    
    char temp;
    for(int i=0; i<C; i++){
        cin >> temp;
        alpa.push_back(temp);
    }
}

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    sort(alpa.begin(), alpa.end());
    dfs(0, 0, 0, 0);
    
    return 0;
}
