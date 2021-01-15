#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    
    for(int i = 1 ; i < n+1 ; i++)
    {
        for(int j = i ; j < n+1 ; j++)
        {
            sum += j;
            if(sum >= n)
            {
                if(sum == n) answer++;
                sum = 0;
                break;
            }
        }
    }
    return answer;
}
