#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string new_id) {
    
    //1단계
    for(int i=0;i<new_id.size();i++)  new_id[i] = tolower(new_id[i]);
    
    //2단계
    string tmp = "";
    for(int i=0;i<new_id.size();i++){
        if(isalpha(new_id[i]) || isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            tmp += new_id[i];    
    }
    new_id = tmp;
    
    //3단계
    while(1){
        if(new_id.find("..") == string::npos) break;
        else new_id.replace(new_id.find(".."), 2, ".");
    }
    
    //4단계
    if(new_id.size()>=1 && new_id[0] == '.') new_id.erase(0, 1);
    if(new_id.size()>=1 && new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1, 1);
    
    //5단계
    if(new_id.empty()) new_id = 'a';
    
    //6단계
    if(new_id.size() >= 16) new_id.erase(15, new_id.size()-15);
    if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1, 1);
    
    //7단계
    if(new_id.size() <= 2){
        string temp = "";
        for(int i=0;i<3-new_id.size();i++) temp += new_id[new_id.size()-1];
        new_id += temp;
    }
    
    return new_id;
}
