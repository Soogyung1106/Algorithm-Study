#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> num; //숫자
vector<char> op; //연산자 차례로 담음
vector<char> p; //연산자 종류를 담음

void split(string& exp){
    
    string s = "";
    for(int i=0;i<exp.size();i++){
        
        if(isdigit(exp[i])) s += exp[i];
        else{ //연산자를 만나면
            num.push_back(stoi(s)); 
            s = "";
            op.push_back(exp[i]);
            if(find(p.begin(), p.end(), exp[i]) == p.end()) p.push_back(exp[i]);
        }    
    }
    
    num.push_back(stoi(s)); 
}

long long solution(string expression) {
    
    //숫자와 연산자를 나눠 담기
    split(expression);
    
    //순열 돌리기 전 정렬
    sort(p.begin(), p.end());
    
    //op와 num 벡터의 값이 계속 바뀌므로
    vector<char> tmp_op = op; vector<long long> tmp_num = num; 
    
    //연산자 우선순위에 따라 num에 있는 값들 계산해주고 삭제해주기 
    long long answer = 0; 
    do{
        for(int i=0;i<p.size();i++){ //p[i]가 연산자 우선순위 

            for(int j =0;j<op.size();j++){
                
                if(p[i] == op[j]){
                    if(p[i] == '+') num[j] += num[j+1];
                    if(p[i] == '-') num[j] -= num[j+1];
                    if(p[i] == '*') num[j] *= num[j+1];
                    
                    //op에서 해당 연산자 삭제 
                    //num에서 해당 피연산자 삭제
                    op.erase(op.begin()+j); 
                    num.erase(num.begin()+j+1); 
                    j--;
                }//end if
                
            }
        }
        
        if(answer<abs(num[0])) answer = abs(num[0]);
        op = tmp_op; num = tmp_num;
        
    }while(next_permutation(p.begin(), p.end())); //순열
    
    return answer;
}
