#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<string> s; //제재 목록(가능한 경우를 문자열로 저장.)

bool is_mapping(string banned, string id){
    if(banned.size() != id.size()) return false;
    
    for(int i = 0;i<banned.size();i++){
        if(banned[i] == '*') continue;
        if(banned[i] != id[i]) return false;
    }
    return true;
}

void dfs(vector<string> user_id, vector<string> banned_id, vector<string> list){
    
    //기저조건: 제재 목록에 담기.
    if(banned_id.empty()){ 
        sort(list.begin(), list.end()); //사전순 정렬
        string answer = "";
        for(auto l : list) answer += l;
        if(!s.count(answer)) s.insert(answer);
        return;
    }
    
    //for문 돌면서 매핑되는 것 찾기  
    string banned = banned_id.front(); //찾으려고 하는 불량 사용자
    banned_id.erase(banned_id.begin()); //맨 앞 삭제
    
    for(int i = 0;i<user_id.size();i++){ //사용자 목록
        vector<string> tmp_user = user_id; 
        vector<string> tmp_list = list;
        
        //매핑되면... 
        if(is_mapping(banned, user_id[i])){
            tmp_list.push_back(user_id[i]);   //tmp_list에 추가
            tmp_user.erase(tmp_user.begin()+i); //tmp_banned 목록과 tmp_user 목록에서 삭제(i번째 삭제.)
            dfs(tmp_user, banned_id, tmp_list);  //재귀호출하기.
        }    
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    
    vector<string> list; //제재목록
    dfs(user_id, banned_id, list); 
    return s.size(); //집합에 저장된 제재 목록의 개수 
}
