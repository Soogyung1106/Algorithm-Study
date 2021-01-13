#include<string>
#include <vector>

using namespace std;

bool solution(string s)
{
    vector<char> v; //스택구조 활용
    for(int i=0;i<s.size();i++){
        
        if(v.empty()) v.push_back(s[i]);
        else{
            if(s[i] == '(') v.push_back(s[i]);
            else  v.pop_back();
        }        
    }
    
    return v.empty() ? true : false;
}
