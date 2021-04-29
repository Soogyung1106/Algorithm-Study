#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <tuple>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    //조합을 이루는 가능한 모든 문자들 
    set<char> s;
    for(auto order : orders){
        for(int i=0;i<order.size();i++){
            if(!s.count(order[i]))
                s.insert(order[i]);
        }
    }

    vector<char> combi;
    for(auto e : s)  combi.push_back(e);
    
    //검색 빠르게 하도록..
    sort(combi.begin(), combi.end());
    sort(orders.begin(), orders.end());
    
    //course에 대해서 가능한 모든 조합. 
    vector<string> answer;
    for(auto len : course){
        
        vector<int> tmp(combi.size(), 0);
        for(int j=0;j<len;j++)  tmp[j] = 1;
        sort(tmp.begin(), tmp.end());
        
        vector<pair<string, int>> candi; //len 길이의 후보군, 반복 개수
        int MAX = 0;
        do{
            string menus = ""; //len 길이의 가능한 조합.
            for(int k = 0;k<tmp.size();k++){
                if(tmp[k] == 1)
                    menus += combi[k];
            }
            
             //반복 개수세기.
            int cnt = 0;
            for(auto order : orders){
                bool flag = true;
                for(auto menu : menus){ //order에 menu가 모두 포함되어 있는가?
                    if(order.find(menu) == string::npos){
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
            }
            
            if(cnt) candi.push_back({menus, cnt});
            MAX = max(MAX, cnt);
            
        }while(next_permutation(tmp.begin(), tmp.end()));
        
        //최대반복 메뉴들만 answer에 push
        if(MAX < 2) continue;
        for(auto e : candi){
            if(e.second == MAX) answer.push_back(e.first);
        } 
    }
    
    //answer에 담긴 것 사전순으로 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}