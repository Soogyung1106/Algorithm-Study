//
//  main.cpp
//  [2800] 괄호제거
//
//  Created by 정하림 on 2021/06/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <set>

using namespace std;

string s;
vector<int> comb;
bool visit[10];
vector<pair<int, int>> p;
vector<string> result;
set<string> answer;

void dfs(int idx, int cnt) {
    if (comb.size() == cnt) {
        string temp = s;
        for (int i : comb) {
            temp[p[i].first] = 'x';
            temp[p[i].second] = 'y';
        }
        result.push_back(temp);
        return;
    }
    for (int i = idx; i < p.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            comb.push_back(i);
            dfs(i+1, cnt);
            comb.pop_back();
            visit[i] = false;
        }
    }
}

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
        
    stack<int> bracket;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            bracket.push(i);
        }
        else if (s[i] == ')')
        {
            p.push_back({ bracket.top(), i });
            bracket.pop();
        }
    }
    
    for(int i=1; i<=p.size(); i++){
        dfs(0, i);
    }
    
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            result[i].erase(remove(result[i].begin(), result[i].end(), 'x'), result[i].end());
            result[i].erase(remove(result[i].begin(), result[i].end(), 'y'), result[i].end());
        }
        answer.insert(result[i]);
    }
        
    for(auto temp : answer){
        cout << temp << "\n";
    }
    
    return 0;
}
