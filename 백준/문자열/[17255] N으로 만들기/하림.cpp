//
//  main.cpp
//  [17255] N으로 만들기
//
//  Created by 정하림 on 2021/07/02.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> answer;

int cnt;

void dfs(string n, string result){
    if(n==""){
        answer.insert(result);
        return;
    }
    
    result += n;
    
    dfs(n.substr(1), result);
    dfs(n.substr(0,n.length()-1), result);
}

int main(int argc, const char * argv[]) {
    
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    
    string N;
    
    cin >> N;
    
    dfs(N, "");
    
    cout << answer.size() << "\n";
    
    return 0;
}
