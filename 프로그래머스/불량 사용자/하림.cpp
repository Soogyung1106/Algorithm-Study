#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> s;
bool visited[8];

void calc(int index, string result, vector<string> user_id, vector<string> banned_id){
    
    // 재귀의 종료 시점
    if(index==banned_id.size()){
        sort(result.begin(), result.end());
        s.insert(result);
        return;
    }
    
    // 사용자 리스트를 순회하며 제제 사용자를 판별
    for(int i=0; i<user_id.size(); i++){
        
        if(banned_id[index].length() != user_id[i].length()){
            continue;
        }
        
        if(visited[i]){
            continue;
        }
        
        bool flag = true;    
        
        // *를 제외한 문자가 모두 같은 사용자의 인덱스를 제제 아이디에 추가하며 재귀
        for(int j=0; j<banned_id[index].length(); j++){
            if(banned_id[index][j] == '*'){
                continue;
            }
            if(banned_id[index][j] != user_id[i][j]){
                flag = false;
                break;
            }
        }
        
        // 만약 사용자의 아이디가 벤리스트에 들어있다면 확인하며 재귀
        if(flag){
            visited[i] = true;
            calc(index+1, result+to_string(i), user_id, banned_id);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    int answer = 0;
    calc(0, "", user_id, banned_id);
    answer = s.size();
    
    return answer;
}
