#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 0; 
    int end = (n%2==0) ? n/2 : (n+1)/2;
    for(int i=1;i<=end;i++){
        int sum = 0;
        for(int j=i;j<=end;j++){
            sum+=j;
            if(sum == n){
                answer++; 
                break;
            }else if(sum > n) break;
        }
    }
    
    return answer+1; //단독 n인 경우
}
