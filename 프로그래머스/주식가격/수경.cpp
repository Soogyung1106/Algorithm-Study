#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0;i<prices.size();i++){
        if(i == prices.size()-1){
            answer.push_back(0); 
            return answer;
        }
        int count = 0;
        for(int j=i+1;j<prices.size();j++){
            if(prices[i]<=prices[j]) count++;
            else{
                count++; 
                break;
            }
        }
        answer.push_back(count);
    }

}
