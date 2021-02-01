#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    
    //숫자와 연산자 분리 
    vector<long long> num; vector<char> op; 
    vector<char> permu; 
    string tmp = "";
    for(auto ex: expression){
        if(isdigit(ex)) tmp += ex;
        else{
            num.push_back(stoi(tmp));
            tmp = "";
            
            op.push_back(ex);
            if(find(permu.begin(), permu.end(), ex) == permu.end())
                permu.push_back(ex);
        }
    }
    num.push_back(stoi(tmp));
    
    //연산자 순열 돌리기
    long long max = 0;
    vector<long long> tmp_num = num; vector<char> tmp_op = op;
    sort(permu.begin(), permu.end());
    do{
        for(auto p : permu){
            for(int i = 0; i<op.size();i++){
                
                if(p == op[i]){    
                    if(p == '+') num[i] += num[i+1];
                    if(p == '-') num[i] -= num[i+1];
                    if(p == '*') num[i] *= num[i+1];
                    //삭제 후 넣기
                    num.erase(num.begin()+i+1);
                    op.erase(op.begin()+i);
                    i--;
                }
            }
        }
        
        if(abs(num.front())>max) max = abs(num.front());
        
        //초기화
        num.clear(); op.clear();
        num = tmp_num; op = tmp_op;
        
    }while(next_permutation(permu.begin(), permu.end()));
        
    return max;
}
