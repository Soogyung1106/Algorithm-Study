#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    vector<int> answer{0, 1};
    vector<string> v; string tmp = ""; int i= 0; 
    for(auto elem : words){
        i++; 
        if(i > n){ i %= n; answer[1]++; }    
         
        if(!v.empty() && (elem.size() == 1 || tmp[tmp.size()-1] != elem[0] || find(v.begin(), v.end(), elem) != v.end())){ 
            answer[0] = i; 
            return answer;
        }   
        
        v.push_back(elem); 
        tmp = elem;
    }
    
    return {0, 0};
}