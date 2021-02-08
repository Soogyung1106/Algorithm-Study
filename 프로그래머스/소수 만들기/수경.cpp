#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int num){
    int count = 0;
    for(int i=1;i<=num;i++){
        if(num%i == 0) count++;
        if(count>=3) break;
    }
    return count == 2 ? true : false;
}

int solution(vector<int> nums) {
    //배열 생성
    vector<int> idx(nums.size(), 0);
    for(int i=0;i<3;i++) idx[i] = 1;    
    sort(idx.begin(), idx.end());
    
    //경우의 수를 구하기(조합 nCk)
    int answer = 0;
    do{
        int sum = 0;
        for(int i=0;i<idx.size();i++){
            if(idx[i] != 0) sum += nums[i];
        }
        
        if(isPrime(sum)) answer++;
        
    }while(next_permutation(idx.begin(), idx.end()));
    
    return answer;
}
