#include <string>
#include <vector>

using namespace std;

int answer = 0;
int t = 0;
vector<int> nums; 

//numbers[idx]에 + 연산 혹은 - 연산을 함. 
//누적해서 sum에 더함. -> target 넘버일 경우 answer++ 
void makeTarget(int idx, int sum){
    //기저조건
    if(idx == nums.size()){
        if(sum == t) answer++;
        return;
    }
    
    makeTarget(idx+1, sum + nums[idx]); // 1, 0에서의 값. 
    makeTarget(idx+1, sum - nums[idx]); // 3, 2에서의 값
                                    
}

int solution(vector<int> numbers, int target) {
    t = target;
    nums = numbers;   
    makeTarget(0, 0); //타겟넘버를 만들 수 있는 '경우의 수'를 구하는 함수. 
    return answer;
}
